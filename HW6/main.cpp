#include <iostream>
#include <string>
#include <../../OpenBLAS/cblas.h>

#include "power_spectrum.h"
#include "read_file.h"

using namespace std;

int main(){
  //Define the file which we want to take data from
  string file1 = "data/detection01.nc";
  string file2 = "data/detection02.nc";
  
  //Does the fft from the file
  rarray<std::complex<double>,1> fft1 = read_file(file1);
  rarray<std::complex<double>,1> fft2 = read_file(file2);

  const double* power1(power_spectrum(fft1));
  const double* power2(power_spectrum(fft2));
  int unity = 1;
  int dimension = fft1.size();

  //std::cout<<dimension<<" "<<sizeof(power1)/sizeof(*power1)<<endl;
  //double correlation_f_g[dimension];
  
  std::cout<<"doing correlation"<<std::endl;
  double correlation_f_g = cblas_ddot(dimension,power1,unity,power2,unity);
  std::cout<<"Done correlation"<<std::endl;
  
  cout<<correlation_f_g<<endl;

  cout<<"all good"<<endl;

  return 0;
}
