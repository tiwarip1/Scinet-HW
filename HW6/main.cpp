#include <iostream>
#include <string>

#include "read_file.h"

using namespace std;

int main(){

  string file_name = "data/detection01.nc";

  rarray<std::complex<double>,1> fft = read_file(file_name);

  return 0;
}
