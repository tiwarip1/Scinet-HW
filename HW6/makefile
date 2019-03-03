CXX=g++
GSLBASE?=${SCINET_GSL_ROOT}/
GSLINC=${GSLBASE}include
GSLLIB=${GSLBASE}lib
BLAS_INC=${HOME}/OpenBLAS/include/
BLAS_LIB=${HOME}/OpenBLAS/lib/
CXXFLAGS=-std=c++11 -g -O2 -march=native -ftree-vectorize -Wall
LDLIBS=-I${BLAS_INC} -L${BLAS_INC} -lgsl -lgslcblas -lblas -lnetcdf_c++4 -lfftw3 -lopenblas


all: main.o read_file.o fft_fast.o power_spectrum.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS};\
	./all

main.o: main.cpp
	${CXX} ${CXXLAGS} -c -o $@ $^

read_file.o: read_file.cpp
	${CXX} ${CXXLAGS} -c -o $@ $^

fft_fast.o: fft_fast.cpp
	${CXX} ${CXXLAGS} -c -o $@ $^

power_spectrum.o: power_spectrum.cpp
	${CXX} ${CXXLAGS} -c -o $@ $^


clean:
	rm -f *.o;\
	rm -f all
