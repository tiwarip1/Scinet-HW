#ifndef _RUN_
#define _RUN_

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;
#include <rarray>

#include "count_ants.h"
#include "Randpartition.h"

rarray<int,2> run_once(int length, rarray<int,2> new_number_of_ants, rarray<int,2> number_of_ants, int nmoves, size_t seed, int* partition, const int* jmoves, const int* imoves, int total_ants, int nmin, int nmax, int t);

#endif
