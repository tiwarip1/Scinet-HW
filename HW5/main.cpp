#include <iostream>
#include <gsl/gsl_odeiv2.h>

int
func (double t, const double y[], double f[],
      void *params)
{
  (void)(t); /* avoid unused parameter warning */
  double mu = *(double *)params;
  f[0] = -y[4]*y[0]*y[2]-y[6]*y[0]*y[1];
  f[1] = -y[5]*y[1]*y[2]+y[6]*y[0]*y[1];
  f[2] = y[4]*y[0]*y[2]+y[5]*y[1]*y[2]-y[3]*y[1]*y[2];
  return GSL_SUCCESS;
}

void main(){
  //Defining all the static variables
  float B = 0.02;
  float E = 0.015;
  float A = 0.03;
  float C = 0.01;
  int K0 = 9;
  //S=0, K=1, Z=2, A=3, B=4, C=5, E=6
  gsl_odeiv2_system system = {func,jac,2,&K0);

}
