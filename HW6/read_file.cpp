#include <rarray>
#include <netcdf>
#include <complex>
#include <fftw3.h>
#include <string>

#include "read_file.h"
#include "fft_fast.h"

using namespace std;
using namespace netCDF;
//This file takes a filename from main, which it then uses to find a netcdf file at that location. Given this data, the information is taken and put through a fast fourier transform that was given in a slide from class. This fourier transofmred rarray is outputted

rarray<std::complex<double>,1> read_file(string file_name){

  //Finds file and collects data
  netCDF:;NcFile file(file_name, netCDF::NcFile::read);
  rarray<std::complex<double>,1> f(file.getDim("nt").getSize());
  file.getVar("f").getVar(&f[0]);

  //defines another array to store fourier transformed data into
  rarray<std::complex<double>,1> fhat(file.getDim("nt").getSize());
  bool inverse = false;

  //Does the transformation
  fft_fast(f,fhat,inverse);

  //If you want to check the output, the for loop is there
  /*
  for(size_t i=0;i<fhat.size();i++){
    cout<<fhat[i]<<"     "<<f[i]<<endl;
    }*/

  return fhat;
}
