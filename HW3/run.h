#ifndef _RUN_
#define _RUN_

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;

#include "count_ants.h"
#include "Randpartition.h"

int* run_once(int length, int* new_number_of_ants, int* number_of_ants, int nmoves, size_t seed, int* partition, const int* jmoves, const int* imoves, int total_ants, int nmin, int nmax, int t);

#endif