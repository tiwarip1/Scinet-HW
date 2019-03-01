CXX=g++
GSLBASE?=${SCINET_GSL_ROOT}/
GSLINC=${GSLBASE}include
GSLLIB=${GSLBASE}lib
CXXFLAGS=-std=c++11 -g -O2 -march=native -ftree-vectorize -Wall
LDLIBS=-lgsl -lgslcblas -lnetcdf_c++4

all: function.o jacobian.o main.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS};\
	./all>output.txt

function: function.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

function.o: function.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $^

jacobian: jacobian.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

jacobian.o: jacobian.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $^

main: main.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $^

clean:
	rm -f *.o all
