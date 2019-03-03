#include <iostream>
#include <string>
#include <openblas>

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

  rarray<std::complex<double>,1> power1 = power_spectrum(fft1);
  rarray<std::complex<double>,1> power2 = power_spectrum(fft2);

  double correlation_f_g = cblas_ddot(power1.size(),power1,1,power2,1);

  cout<<correlation_f_g<<endl;

  cout<<"all good"<<endl;

  return 0;
}
