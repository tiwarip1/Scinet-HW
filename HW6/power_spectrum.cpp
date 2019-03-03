#include <rarray>
#include <complex>

#include "power_spectrum.h"

//This function takes an array of comple doubles and squares the items in the array
rarray<std::complex<double>,1> power_spectrum(rarray<std::complex<double>,1>& fft){

  //Defines the array to be outputted
  rarray<std::complex<double>,1> power=fft;

  for(size_t i=0; i<fft.size();i++){
    //Suqares each element
    power[i] = std::pow(fft[i],2);

  }

  return power;

}
