#ifndef CACHE_H
#define CACHE_H


#include "inttypes.h"
#include <vector>
#include <queue>
#include <list>

class Cache{
    private:
        typedef struct {
            uint32_t validBit;
            uint32_t lastAddr;
            std::list<uint32_t> tagIndexQ;
            char* blocks;   // Flattened 2D array for blocks, you'll need to add some conversion for head & tail var to match with tag array
        } StreamBuff;

        typedef struct {
            uint32_t validBit;
            uint32_t dirtyBit;
            uint32_t addr;
            uint32_t tag;
            char* dataBlock;
        } CacheLine;

        const char* name = "";
        uint32_t size;     // Cache size in bytes
        uint32_t assoc;    // Associativity (Number of ways)
        uint32_t blockSize;    // Block size in bytes
        uint32_t numSets;      // Number of sets in cache
        uint32_t numOffsetBits;
        uint32_t numIndexBits;
        uint32_t indexMask;     // Index bits mask
        uint32_t tagMask;       // Tag bits mask
        uint32_t tagIndexMask;

        std::vector<std::list<CacheLine>> cache;

        uint32_t strmBuff_N;       // Number of stream buffers
        uint32_t strmBuff_M;       // Size of each stream buffer (each element is size of blockSize)
        std::list<StreamBuff> streamBuffQueue; // Make a circular linked list for stream buff in the class definition in the constructor.
        Cache* nextLevel = NULL;        // Next level cache

        // Measurements
        int reads = 0;
        int readMisses = 0;
        int writes = 0;
        int writeMisses = 0;
        double missRate = 0.000000f;
        int writeBacks = 0;
        int prefetches = 0;
        int readsFromPrftch = 0;
        int readMissesFromPrftch = 0;
        int memTraffic = 0;

    public:
        // NOTE: Using a flattened 2D array approach for better locality in real physical cache.
        Cache(const char* name, uint32_t size, uint32_t assoc, uint32_t blockSize, uint32_t strmBuff_N, uint32_t strmBuff_M);

        ~Cache();

        void appendMem(Cache* cache);

        // Function that takes in the address to find the set and tag of a block in the cache.
        CacheLine* decoder(uint32_t addr, uint32_t* tag, uint32_t* index);

        char* read(uint32_t addr);

        // WBWA policy.
        void write(uint32_t addr);

        void writeBack(uint32_t addr, char* dataBlock);

        // This will search the stream buffer for the requested block. If the block is found then the function will
        // return the vector of bytes from the block, which should be vector<char> of size = blockSize.
        char* searchStreamBuffs(uint32_t addr, bool isHit);

        // Head will be the X+1 so don't shift up one anymore.
        void prefetch(StreamBuff& streamBuff);

        // Output details of the cache simulation.
        void cacheContents();

        void streamBufferContents();

        void measurements();
};

#endif