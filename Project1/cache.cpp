#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <cstring>
#include <cassert>
#include "include/cache.h"

using namespace std;

void printBits(uint32_t value);

Cache::Cache(const char* name, uint32_t size, uint32_t assoc, uint32_t blockSize, uint32_t strmBuff_N, uint32_t strmBuff_M){
    this->name = name;

    // Dimesions of Cache.
    this->size = size;
    this->assoc = assoc;
    this->blockSize = blockSize;
    this->numSets = size / (assoc * blockSize);

    // Code to generate bit masks...
    this->numOffsetBits = std::log2(this->blockSize);
    this->numIndexBits = std::log2(this->numSets);
    this->indexMask = ((1 << numIndexBits) - 1) << numOffsetBits;
    this->tagMask = 0xFFFFFFFF << (numIndexBits + numOffsetBits);
    this->tagIndexMask = 0xFFFFFFFF << numOffsetBits;

    // Initializing cache
    this->cache.resize(this->numSets);

    // Sizes for the stream buffer.
    this->strmBuff_N = strmBuff_N;      // Size of queue holding multiple stream buffers
    this->strmBuff_M = strmBuff_M;      // Size of each stream buffer
    for(uint32_t i = 0; i < this->strmBuff_N; i++){     // Initializing stream buffers
        StreamBuff buff;
        buff.validBit = 0;
        buff.blocks = (char*)malloc(this->strmBuff_M * this->blockSize * sizeof(char));    // REMEMBER TO FREEEEEE MEEE
        this->streamBuffQueue.push_back(buff);
    }
}

Cache::~Cache() {
    // Free all cache line data blocks
    for(auto& set : this->cache) {
        for(auto& line : set) {
            if(line.dataBlock != nullptr) {
                free(line.dataBlock);
            }
        }
    }

    // Free stream buffers
    for(auto& buff : this->streamBuffQueue) {
        if(buff.blocks != nullptr) {
            free(buff.blocks);
        }
    }
}

void Cache::appendMem(Cache* cache){
    this->nextLevel = cache;
}

/**
* Decoder will look for the tag if it is in the cache. It should return 0 if tag found,
* if it is not found it returns -1.
*/
Cache::CacheLine* Cache::decoder(uint32_t addr, uint32_t* tag, uint32_t* index){
    *tag = (addr & (this->tagMask))  >> (this->numIndexBits + this->numOffsetBits);
    *index = (addr & (this->indexMask)) >> this->numOffsetBits;

    // For each element in the set
    auto& set = this->cache.at(*index);
    for(auto it = set.begin(); it != set.end(); ++it) {
        if(it->tag == *tag && it->validBit == 1) {
            set.splice(set.end(), set, it);     // If hit we also update recency while we're at it, two birds one stone.
            return &set.back();
        }
    }

    // If flow reaches here, was a MISS.
    if(set.size() >= this->assoc){          // If we have a full set(Conflict/Capacity miss)...
        if(set.front().dirtyBit == 1){      // If next level exists and LRU is dirty...
            this->writeBacks++;
            if(this->nextLevel != NULL){
                this->nextLevel->write(set.front().addr);   // Write-Back to next level cache
            }else{
                this->memTraffic++;
            }
        }
        free(set.front().dataBlock);      // Free the LRU data block, then...
        set.pop_front();            // Evicting LRU
    }
    return NULL;
}

/**
* Reads the requested block from the cache.
* @param addr is the 32-bit address of the requested block
*/
char* Cache::read(uint32_t addr){
    this->reads++;
    uint32_t tag;
    uint32_t index;

    CacheLine* matchingBlock = decoder(addr, &tag, &index);

    char* blockInStreamBuff = NULL;
    if(strmBuff_N != 0){
        bool isHit = (matchingBlock != NULL);
        blockInStreamBuff = searchStreamBuffs(addr, isHit);
        if(matchingBlock != NULL && blockInStreamBuff != NULL){     // Hit in cache and stream buffer
            prefetch(this->streamBuffQueue.front());
        }
    }

    auto& set = this->cache.at(index);
    if(matchingBlock == NULL){      // Miss in cache
        CacheLine newBlock;
        newBlock.validBit = 1;
        newBlock.dirtyBit = 0;
        newBlock.addr = addr;
        newBlock.tag = tag;
        newBlock.dataBlock = (char*)malloc(this->blockSize * sizeof(char));

        if(blockInStreamBuff != NULL){      // Hit in the stream buff
            newBlock.dataBlock = blockInStreamBuff;
            prefetch(this->streamBuffQueue.front());
        }else if(this->strmBuff_N != 0){      // Miss in stream buff and have one to begin with...
            this->readMisses++;
            prefetch(this->streamBuffQueue.front());
        }else{
            this->readMisses++;
        }

        if(this->nextLevel != NULL){
            char* nextLevelData = this->nextLevel->read(addr);
            std::memcpy(newBlock.dataBlock, nextLevelData, this->blockSize);
        }else{
            this->memTraffic++;
        }
        set.push_back(newBlock);
    }

    return set.back().dataBlock;
}

/**
* Write function using write-back with write-through policies
* @param addr is the 32-bit address for the requested block
*/
void Cache::write(uint32_t addr){
    this->writes++;
    uint32_t tag;
    uint32_t index;

    CacheLine* matchingBlock = decoder(addr, &tag, &index);
    char* blockInStreamBuff = NULL;
    if(strmBuff_N != 0){
        bool isHit = (matchingBlock != NULL);
        blockInStreamBuff = searchStreamBuffs(addr, isHit);
        if(matchingBlock != NULL && blockInStreamBuff != NULL){     // Hit in cache and stream buffer
            prefetch(this->streamBuffQueue.front());
        }
    }

    auto& set = this->cache.at(index);
    if(matchingBlock == NULL){

        CacheLine newBlock;     // Create new block to push to the end of the set as MRU
        newBlock.validBit = 1;
        newBlock.dirtyBit = 1;
        newBlock.addr = addr;
        newBlock.tag = tag;
        newBlock.dataBlock = (char*)malloc(this->blockSize * sizeof(char));

        if(blockInStreamBuff != NULL){      // Hit in the stream buff
            newBlock.dataBlock = blockInStreamBuff;
            prefetch(this->streamBuffQueue.front());
        }else if(this->strmBuff_N != 0){      // Miss in stream buff and have one to begin with...
            prefetch(this->streamBuffQueue.front());
            this->writeMisses++;
        }else{
            this->writeMisses++;
        }

        if(this->nextLevel != NULL){
            char* nextLevelData = this->nextLevel->read(addr);
            std::memcpy(newBlock.dataBlock, nextLevelData, this->blockSize);
        }else{
            this->memTraffic++;     // Access main mem for the read from memory
        }
        set.push_back(newBlock);
    }else{
        set.back().dirtyBit = 1;
        memcpy(set.back().dataBlock, matchingBlock->dataBlock, this->blockSize);
    }
}

void Cache::writeBack(uint32_t addr, char* dataBlock){
    this->writes++;
    uint32_t tag;
    uint32_t index;

    CacheLine* matchingBlock = decoder(addr, &tag, &index);
    auto& set = this->cache.at(index);
    if(matchingBlock == NULL){
        CacheLine newBlock;     // Create new block to push to the end of the set as MRU
        newBlock.validBit = 1;
        newBlock.dirtyBit = 1;
        newBlock.addr = addr;
        newBlock.tag = tag;
        newBlock.dataBlock = (char*)malloc(this->blockSize * sizeof(char));
        std::memcpy(newBlock.dataBlock, dataBlock, this->blockSize);
        set.push_back(newBlock);
        this->writeMisses++;
    }else{
        matchingBlock->dirtyBit = 1;
        std::memcpy(matchingBlock->dataBlock, dataBlock, this->blockSize);
    }
}

/**
* Searches each stream buffer in the queue. First checks int the stream buff struct's valid bit is 1, meaning it is
* populated. If populated, seach the buffer, else check next buffer in the queue.
* If buffer was used to supply block, new stream was inserted to buffer, or a buffer is being kept in sync, we make that
* buffer the MRU.
* If no block is found in any buffer, the LRU will be the buffer to be repopulated.
* Use the MRU buffer that has the first instance of a matching block, and you can ignore other hits.
* If you find block, return the dataBlock chunk. (remember it is 1D, use proper indexing to retrieve the block).
* If miss all stream buffers, return NULL.
*/
char* Cache::searchStreamBuffs(uint32_t addr, bool isHit){
    uint32_t tagIndexBits = (addr & (this->tagIndexMask)) >> this->numOffsetBits;
    for(auto sb = streamBuffQueue.begin(); sb != streamBuffQueue.end(); ++sb){  // search from MRU to LRU
        if(sb->validBit == 1){;
            for(auto qElem = sb->tagIndexQ.begin(); qElem != sb->tagIndexQ.end(); qElem++){
                if(*qElem == tagIndexBits){
                    char* foundBlock = (char*)malloc(this->blockSize * sizeof(char));
                    sb->lastAddr = sb->tagIndexQ.back(); // found address <1,2,3^,4,5>6,7,8
                    sb->tagIndexQ.erase(sb->tagIndexQ.begin(), std::next(qElem));
                    this->streamBuffQueue.splice(this->streamBuffQueue.begin(), this->streamBuffQueue, sb);
                    return foundBlock;
                }
            }
        }
    }
    if(!isHit){
        auto lruSB = std::prev(this->streamBuffQueue.end());// <sb1,sb2,sb3,sb4>(end));
        lruSB->lastAddr = tagIndexBits;
        this->streamBuffQueue.splice(this->streamBuffQueue.begin(), this->streamBuffQueue, lruSB);
    }

    return NULL;
}

/**
 * Prefetches the next consecutive blocks for the stream buffer that was passed is with the address passed in.
 */
void Cache::prefetch(StreamBuff& sb){
    if(sb.tagIndexQ.size() == this->strmBuff_M){
        sb.tagIndexQ.clear();
    }
    uint32_t iterations = this->strmBuff_M - sb.tagIndexQ.size();

    for(uint32_t i = 1; i <= iterations; i++){
        sb.tagIndexQ.push_back(sb.lastAddr + i);
        this->prefetches++;
        this->memTraffic++;
    }
    //this->memTraffic++;
    sb.validBit = 1;
}

void Cache::cacheContents(){
    printf("===== %s contents =====\n", this->name);

    uint32_t setNum = 0;
    for(auto& set : this->cache){
        if(set.size() != 0){    // If the set is valid
            printf("set      %d: ", setNum);
        }
        for(auto way = set.rbegin(); way != set.rend(); ++way){   // The set is a linked list, will hold whatever new blocks come in, size not preinit
            const char* isDirty = (way->dirtyBit == 1) ? "D" : " ";
            printf("  %x %s", way->tag, isDirty);
        }
        printf("\n");
        setNum++;
    }
    printf("\n");
}

void Cache::streamBufferContents(){
    printf("===== Stream Buffer(s) contents =====\n");
    for(auto& sb : this->streamBuffQueue){
        for(auto qElem = sb.tagIndexQ.begin(); qElem != sb.tagIndexQ.end(); qElem++){
            printf(" %x ", *qElem);
        }
        printf("\n");
    }
    printf("\n");
}

void Cache::measurements(){
    this->memTraffic = this->readMisses + this->writeMisses + this->prefetches + this->writeBacks;

    if(this->name == "L1"){
        this->missRate = ((float)(this->readMisses + this->writeMisses) / (float)(this->reads + this->writes));
        printf("===== Measurements =====\n");
        printf("a. %s reads:                   %d\n", this->name, this->reads);
        printf("b. %s read misses:             %d\n", this->name, this->readMisses);
        printf("c. %s writes:                  %d\n", this->name, this->writes);
        printf("d. %s write misses:            %d\n", this->name, this->writeMisses);
        printf("e. %s miss rate:               %.4f\n", this->name, this->missRate);
        printf("f. %s writebacks:              %d\n", this->name, this->writeBacks);
        printf("g. %s prefetches:              %d\n", this->name, this->prefetches);
        if(this->nextLevel == NULL){
            printf("h. L2 reads (demand):          %d\n", 0);
            printf("i. L2 read misses (demand):    %d\n", 0);
            printf("j. L2 reads (prefetch):        %d\n", 0);
            printf("k. L2 read misses (prefetch):  %d\n", 0);
            printf("l. L2 writes:                  %d\n", 0);
            printf("m. L2 write misses:            %d\n", 0);
            printf("n. L2 miss rate:               %.4f\n", 0.0000);
            printf("o. L2 writebacks:              %d\n", 0);
            printf("p. L2 prefetches:              %d\n", 0);
            printf("q. memory traffic:             %d\n", this->memTraffic);
        }
    }else{
        this->missRate = ((float)(this->readMisses) / (float)(this->reads));

        printf("h. %s reads (demand):          %d\n", this->name, this->reads);
        printf("i. %s read misses (demand):    %d\n", this->name, this->readMisses);
        printf("j. %s reads (prefetch):        %d\n", this->name, 0);
        printf("k. %s read misses (prefetch):  %d\n", this->name, 0);
        printf("l. %s writes:                  %d\n", this->name, this->writes);
        printf("m. %s write misses:            %d\n", this->name, this->writeMisses);
        printf("n. %s miss rate:               %.4f\n", this->name, this->missRate);
        printf("o. %s writebacks:              %d\n", this->name, this->writeBacks);
        printf("p. %s prefetches:              %d\n", this->name, this->prefetches);
        printf("q. memory traffic:              %d\n", this->memTraffic);
    }

}


