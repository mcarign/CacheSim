# Cache Simulator
This is my flexible cache and memory hierarchy simulator I built for my Microprocessor Architecture course. This simulator does not cover every single aspect a modern commercial cache can have, but it does simulate the standard and most important aspects of one. This simulator allows for the user to configure the cache's block size, L1/L2 associativity, L1/L2 cache size, number of stream buffers, and stream buffer size. 

### Constraints and details to note about my simulator: 
  - The parameters are that block size and sets must be powers of two,
  - It uses LRU replacement policy,
  - It uses WBWA write policy (Write Back + Write Allocate)
  - If multiple stream buffers have a hit for the same block, I only consider the MRU steam buffer that hit, leaving the others as they are.

### The different hierarchies I explored were:
  - L1
  - L1 + L2
  - L1 + Stream Buffer
  - L1 + L2 + Stream Buffer

## Analysis

### Miss Penalty vs. Cache Size (L1 only, fixed block size of 32B):

<img width="989" height="590" alt="image" src="https://github.com/user-attachments/assets/091b044e-1bd5-4840-bcd8-dc93aa6388b5" />

### Average access Time(AAT) vs. Cache Size (L1 only, fixed block size of 32B):

<img width="989" height="590" alt="image" src="https://github.com/user-attachments/assets/117ea4db-3357-419b-999e-68f0a05cacbb" />

### Miss Rate vs. Block Size (L1 only, varied cache and block size, associativity = 4):

<img width="989" height="590" alt="image" src="https://github.com/user-attachments/assets/e4f399e4-85b3-4a54-a00c-8684d396d6e1" />

### AAT vs. L1 Cache Size (L1 + L2, varied cache size, block size 32B, L1 associativity = 4, L2 associativity = 8):

<img width="989" height="590" alt="image" src="https://github.com/user-attachments/assets/adc93180-d03c-4032-8f0d-2de037ede781" />

### Stream Buffer analysis (L1 only, cache size = 1KB, associativity = 1, block size = 16):

<img width="307" height="211" alt="image" src="https://github.com/user-attachments/assets/542966a7-57aa-41a5-b867-35b641e50dab" />
