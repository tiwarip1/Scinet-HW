#ifndef READ_FILE
#define READ_FILE

#include <rarray>
#include <netcdf>
#include <complex>
#include <string>

using namespace std;

rarray<std::complex<double>,1> read_file(string file_name);

#endif
