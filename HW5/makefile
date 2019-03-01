CXX=g++
CXXFLAGS=-std=c++11 -g -O2 -march=native -ftree-vectorize -Wall
LDLIBS=-lboost_unit_test_framework

all: function.o jacobian.o main.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

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
