#include <complex>
#include <rarray>
#include <fftw3.h>

#include "fft_fast.h"

void fft_fast(const rvector<std::complex<double>>& f, rvector<std::complex<double>>& fhat, bool inverse)
{

  int n = f.size();
  fftw_plan p = fftw_plan_dft_1d(n,
				 (fftw_complex*)f.data(), (fftw_complex*)fhat.data(),
				 inverse?FFTW_BACKWARD:FFTW_FORWARD,
				 FFTW_ESTIMATE);
  fftw_execute(p);
  fftw_destroy_plan(p);

}
