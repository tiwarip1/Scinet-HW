#ifndef POWER_SPECTRUM
#define POWER_SPECTRUM

#include <complex>
#include <rarray>

rarray<std::complex<double>,1> power_spectrum(rarray<std::complex<double>,1>& fft);

#endif
