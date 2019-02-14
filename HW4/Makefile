CXX=g++
CXXFLAGS=-std=c++11 -g -O3 -march=native
CXXFLAGS=-std=c++11 -g -O2 -march=native -ftree-vectorize -Wall

LDFLAGS=-g
LDLIBS=-lboost_unit_test_framework


all: antsontable-orig antsontable

clean: clean-orig clean-new

distclean: clean clean-more

.PHONY: all clean distclean clean-orig clean-new clean-more run-orig run integratedtest help

antsontable-orig.o: antsontable-orig.cc
	${CXX} ${CXXFLAGS} -c -o $@ $^

antsontable-orig: antsontable-orig.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

run-orig: antsontable-orig
	./antsontable-orig > run-orig

clean-orig:
	\rm -f antsontable-orig.o


output.o: output.cc output.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

timestep.o: timestep.cc timestep.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

report.o: report.cc report.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

initialization.o: initialization.cc initialization.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

randompartition.o: randompartition.cc randompartition.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

antsontable.o: antsontable.cc initialization.h report.h timestep.h output.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

antsontable: antsontable.o initialization.o randompartition.o report.o timestep.o output.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

run: antsontable
	./antsontable > run

clean-new:
	\rm -f antsontable.o initialization.o randompartition.o report.o timestep.o output.o all_test.o init_test.o

clean-more:
	\rm -f antsontable antsontable-orig run run-orig

integratedtest: run run-orig
	diff run run-orig

help:
	@echo Type:
	@echo " 'make'                to compile the antsontable and antsontable-orig applications;"
	@echo " 'make run'            to run antsontable;"
	@echo " 'make run-orig'       to run antsontable-orig;"
	@echo " 'make integratedtest' to compare outputs of antsontable and antsontable-orig."
	@echo " 'make clean'          to remove all object files (triggers a full recompile on next 'make')"
	@echo " 'make distclean'      to remove all object files, executables and test outputs"

test: testsuite
	./testsuite;/

testsuite: timestep.o randompartition.o initialization.o report.o init_test.o all_test.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

all_test.o: all_test.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $^

init_test.o: init_test.cpp init_test.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

Boost: Boost_init_test
	./Boost_init_test --log-level all

Boost_init_test: Boost_init_test.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS} 

Boost_init_test.o: Boost_init_test.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<
