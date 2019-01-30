CXX = g++ 
CXXFLAGS=-std=c++11

all : init count_ants Randpartition run main

	${CXX} ${CXXFLAGS} -o antsonatable main.o init.o Randpartition.o count_ants.o run.o -lnetcdf_c++4;\
	./antsonatable>output.dat;\
	tar -zcvf antsonatable.tar.gz .

main : main.cpp

	${CXX} ${CXXFLAGS} -c -o main.o main.cpp

init : init.cpp

	${CXX} ${CXXFLAGS} -c -o init.o init.cpp

count_ants : count_ants.cpp

	${CXX} ${CXXFLAGS} -c -o count_ants.o count_ants.cpp

Randpartition : Randpartition.cpp

	${CXX} ${CXXFLAGS} -c -o Randpartition.o Randpartition.cpp

run : run.cpp Randpartition.h count_ants.h

	${CXX} ${CXXFLAGS} -c -o run.o run.cpp
