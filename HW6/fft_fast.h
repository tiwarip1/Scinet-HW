#ifndef FFT_FAST
#define FFT_FAST

#include <complex>
#include <rarray>
#include <fftw3.h>

void fft_fast(const rvector<std::complex<double>>& f, rvector<std::complex<double>>& fhat, bool inverse);

#endif
