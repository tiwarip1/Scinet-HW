#ifndef _WRITEFILE_
#define _WRITEFILE_

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;
#include <rarray>
#include <netcdf>
using namespace netCDF;

void writing(int total_t,rarray<float,1> t_values, rarray<float,1> nmin_values,
rarray<float,1> nmax_values, rarray<float,1> total_values);

#endif
