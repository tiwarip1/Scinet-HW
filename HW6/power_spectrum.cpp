#include <iostream>
#include <rarray>
#include <complex>

#include "power_spectrum.h"

//This function takes an array of comple doubles and squares the items in the array
double* power_spectrum(rarray<std::complex<double>,1>& fft){

  //Defines the array to be outputted
  int dimension = fft.size();
  std::cout<<"Dimension: "<<dimension<<std::endl;
  double power[dimension];

  for(size_t i=0; i<fft.size();i++){
    //Suqares each element
    double amount = std::real(fft[i]*std::conj(fft[i]));
    power[i] = amount;
    //std::cout<<amount<<std::endl;
  }
  std::cout<<"Made a power spectrum"<<std::endl;
  return power;

}
