CC = g++
OPT = -O3
#OPT = -g
WARN = -Wall
# You can select a C++ standard using the STD define below.  To do so, uncomment (remove leading #) and adjust the standard as needed.
#STD = -std=c++11
CFLAGS = $(OPT) $(WARN) $(STD) $(INC) $(LIB)

# List all your .cc/.cpp files here (source files, excluding header files)
SIM_SRC = sim.cpp cache.cpp

# List corresponding compiled object files here (.o files)
SIM_OBJ = sim.o cache.o

#################################

# default rule

all: sim
	@echo "my work is done here..."
#	./sim 16 1024 1 0 0 0 0 traces/gcc_trace.txt > sim_outputs/output.txt 2> sim_errors/error.txt
#	-diff -iw sim_outputs/output.txt val-proj1/val1.16_1024_1_0_0_0_0_gcc.txt

# Graph 1 outputs: Fixed Block Size -- Varying Cache Size -- Varying Associativity
#	./sim 32 1024 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1024_1_0_0_0_0.txt
#	./sim 32 1024 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1024_2_0_0_0_0.txt
#	./sim 32 1024 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1024_4_0_0_0_0.txt
#	./sim 32 1024 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1024_8_0_0_0_0.txt
#	./sim 32 1024 32 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1024_32_0_0_0_0.txt
#
#	./sim 32 2048 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_2048_1_0_0_0_0.txt
#	./sim 32 2048 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_2048_2_0_0_0_0.txt
#	./sim 32 2048 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_2048_4_0_0_0_0.txt
#	./sim 32 2048 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_2048_8_0_0_0_0.txt
#	./sim 32 2048 64 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_2048_64_0_0_0_0.txt
#
#	./sim 32 4096 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_4096_1_0_0_0_0.txt
#	./sim 32 4096 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_4096_2_0_0_0_0.txt
#	./sim 32 4096 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_4096_4_0_0_0_0.txt
#	./sim 32 4096 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_4096_8_0_0_0_0.txt
#	./sim 32 4096 128 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_4096_128_0_0_0_0.txt
#
#	./sim 32 8192 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_8192_1_0_0_0_0.txt
#	./sim 32 8192 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_8192_2_0_0_0_0.txt
#	./sim 32 8192 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_8192_4_0_0_0_0.txt
#	./sim 32 8192 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_8192_8_0_0_0_0.txt
#	./sim 32 8192 256 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_8192_256_0_0_0_0.txt
#
#	./sim 32 16384 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_16384_1_0_0_0_0.txt
#	./sim 32 16384 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_16384_2_0_0_0_0.txt
#	./sim 32 16384 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_16384_4_0_0_0_0.txt
#	./sim 32 16384 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_16384_8_0_0_0_0.txt
#	./sim 32 16384 512 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_16384_512_0_0_0_0.txt
#
#	./sim 32 32768 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_32768_1_0_0_0_0.txt
#	./sim 32 32768 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_32768_2_0_0_0_0.txt
#	./sim 32 32768 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_32768_4_0_0_0_0.txt
#	./sim 32 32768 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_32768_8_0_0_0_0.txt
#	./sim 32 32768 1024 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_32768_1024_0_0_0_0.txt
#
#	./sim 32 65536 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_65536_1_0_0_0_0.txt
#	./sim 32 65536 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_65536_2_0_0_0_0.txt
#	./sim 32 65536 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_65536_4_0_0_0_0.txt
#	./sim 32 65536 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_65536_8_0_0_0_0.txt
#	./sim 32 65536 2048 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_65536_2048_0_0_0_0.txt
#
#	./sim 32 131072 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_131072_1_0_0_0_0.txt
#	./sim 32 131072 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_131072_2_0_0_0_0.txt
#	./sim 32 131072 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_131072_4_0_0_0_0.txt
#	./sim 32 131072 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_131072_8_0_0_0_0.txt
#	./sim 32 131072 4096 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_131072_4096_0_0_0_0.txt
#
#	./sim 32 262144 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_262144_1_0_0_0_0.txt
#	./sim 32 262144 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_262144_2_0_0_0_0.txt
#	./sim 32 262144 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_262144_4_0_0_0_0.txt
#	./sim 32 262144 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_262144_8_0_0_0_0.txt
#	./sim 32 262144 8192 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_262144_8192_0_0_0_0.txt
#
#	./sim 32 524288 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_524288_1_0_0_0_0.txt
#	./sim 32 524288 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_524288_2_0_0_0_0.txt
#	./sim 32 524288 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_524288_4_0_0_0_0.txt
#	./sim 32 524288 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_524288_8_0_0_0_0.txt
#	./sim 32 524288 16384 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_524288_16384_0_0_0_0.txt
#
#	./sim 32 1048576 1 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1048576_1_0_0_0_0.txt
#	./sim 32 1048576 2 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1048576_2_0_0_0_0.txt
#	./sim 32 1048576 4 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1048576_4_0_0_0_0.txt
#	./sim 32 1048576 8 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1048576_8_0_0_0_0.txt
#	./sim 32 1048576 32768 0 0 0 0 traces/gcc_trace.txt > graph1_outputs/out_g1.32_1048576_32768_0_0_0_0.txt
#
#
## Graph 3: Fixed L1 & L2 Block Size -- Varying L1 Size -- Varying L1 Associativity -- 16KB L2 Size -- 8-Way L2 Associativity
#	./sim 32 1024 1 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_1024_1_16384_8_0_0.txt
#	./sim 32 1024 2 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_1024_2_16384_8_0_0.txt
#	./sim 32 1024 4 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_1024_4_16384_8_0_0.txt
#	./sim 32 1024 8 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_1024_8_16384_8_0_0.txt
#
#	./sim 32 2048 1 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_2048_1_16384_8_0_0.txt
#	./sim 32 2048 2 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_2048_2_16384_8_0_0.txt
#	./sim 32 2048 4 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_2048_4_16384_8_0_0.txt
#	./sim 32 2048 8 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_2048_8_16384_8_0_0.txt
#
#	./sim 32 4096 1 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_4096_1_16384_8_0_0.txt
#	./sim 32 4096 2 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_4096_2_16384_8_0_0.txt
#	./sim 32 4096 4 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_4096_4_16384_8_0_0.txt
#	./sim 32 4096 8 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_4096_8_16384_8_0_0.txt
#
#	./sim 32 8192 1 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_8192_1_16384_8_0_0.txt
#	./sim 32 8192 2 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_8192_2_16384_8_0_0.txt
#	./sim 32 8192 4 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_8192_4_16384_8_0_0.txt
#	./sim 32 8192 8 16384 8 0 0 traces/gcc_trace.txt > graph3_outputs/out_g3.32_8192_8_16384_8_0_0.txt
#
## Graph 4: Varying Block Size -- Varying Cache Size -- 4-Way Associativity
#	./sim 16 1024 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.16_1024_4_0_0_0_0.txt
#	./sim 16 2048 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.16_2048_4_0_0_0_0.txt
#	./sim 16 4096 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.16_4096_4_0_0_0_0.txt
#	./sim 16 8192 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.16_8192_4_0_0_0_0.txt
#	./sim 16 16384 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.16_16384_4_0_0_0_0.txt
#	./sim 16 32768 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.16_32768_4_0_0_0_0.txt
#
#	./sim 32 1024 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.32_1024_4_0_0_0_0.txt
#	./sim 32 2048 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.32_2048_4_0_0_0_0.txt
#	./sim 32 4096 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.32_4096_4_0_0_0_0.txt
#	./sim 32 8192 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.32_8192_4_0_0_0_0.txt
#	./sim 32 16384 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.32_16384_4_0_0_0_0.txt
#	./sim 32 32768 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.32_32768_4_0_0_0_0.txt
#
#	./sim 64 1024 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.64_1024_4_0_0_0_0.txt
#	./sim 64 2048 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.64_2048_4_0_0_0_0.txt
#	./sim 64 4096 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.64_4096_4_0_0_0_0.txt
#	./sim 64 8192 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.64_8192_4_0_0_0_0.txt
#	./sim 64 16384 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.64_16384_4_0_0_0_0.txt
#	./sim 64 32768 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.64_32768_4_0_0_0_0.txt
#
#	./sim 128 1024 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.128_1024_4_0_0_0_0.txt
#	./sim 128 2048 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.128_2048_4_0_0_0_0.txt
#	./sim 128 4096 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.128_4096_4_0_0_0_0.txt
#	./sim 128 8192 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.128_8192_4_0_0_0_0.txt
#	./sim 128 16384 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.128_16384_4_0_0_0_0.txt
#	./sim 128 32768 4 0 0 0 0 traces/gcc_trace.txt > graph4_outputs/out_g4.128_32768_4_0_0_0_0.txt
#
## Graph 5:
#	./sim 32 1024 4 16384 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_1024_4_16384_8_0_0.txt
#	./sim 32 1024 4 32768 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_1024_4_32768_8_0_0.txt
#	./sim 32 1024 4 65536 8 0 0 traces/gcc_trace.txt > graph4_outputs/out_g5.32_1024_4_65536_8_0_0.txt
#
#	./sim 32 2048 4 16384 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_2048_4_16384_8_0_0.txt
#	./sim 32 2048 4 32768 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_2048_4_32768_8_0_0.txt
#	./sim 32 2048 4 65536 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_2048_4_65536_8_0_0.txt
#
#	./sim 32 4096 4 16384 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_4096_4_16384_8_0_0.txt
#	./sim 32 4096 4 32768 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_4096_4_32768_8_0_0.txt
#	./sim 32 4096 4 65536 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_4096_4_65536_8_0_0.txt
#
#	./sim 32 8192 4 16384 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_8192_4_16384_8_0_0.txt
#	./sim 32 8192 4 32768 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_8192_4_32768_8_0_0.txt
#	./sim 32 8192 4 65536 8 0 0 traces/gcc_trace.txt > graph5_outputs/out_g5.32_8192_4_65536_8_0_0.txt

# Table 1: Fixed L1 -- Varying Number of Prefetch Units -- Fixed Prefetch Uint Size
	./sim 16 1024 1 0 0 0 0 traces/streams_trace.txt > table1_outputs/out_t1.16_1024_1_0_0_0_0.txt
	./sim 16 1024 1 0 0 1 4 traces/streams_trace.txt > table1_outputs/out_t1.16_1024_1_0_0_1_4.txt
	./sim 16 1024 1 0 0 2 4 traces/streams_trace.txt > table1_outputs/out_t1.16_1024_1_0_0_2_4.txt
	./sim 16 1024 1 0 0 3 4 traces/streams_trace.txt > table1_outputs/out_t1.16_1024_1_0_0_3_4.txt
	./sim 16 1024 1 0 0 4 4 traces/streams_trace.txt > table1_outputs/out_t1.16_1024_1_0_0_4_4.txt


# rule for making sim

sim: $(SIM_OBJ)
	$(CC) -o sim $(CFLAGS) $(SIM_OBJ) -lm
	@echo "-----------DONE WITH sim-----------"


# generic rule for converting any .cc file to any .o file

.cc.o:
	$(CC) $(CFLAGS) -c $*.cc

# generic rule for converting any .cpp file to any .o file

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp


# type "make clean" to remove all .o files plus the sim binary

clean:
	rm -f *.o sim


# type "make clobber" to remove all .o files (leaves sim binary)

clobber:
	rm -f *.o


