#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

#include "function.h"

int
function (double t, const double y[], double f[],
	  void *params)
{
  (void)(t); /* avoid unused parameter warning */
  double mu = *(double *)params;
  //Define constants
  float B = 0.02;
  float E = 0.015;
  float A = 0.03;
  float C = 0.01;
  //Just the differential equations that were given to us
  f[0] = -B*y[0]*y[2]-E*y[0]*y[1];
  f[1] = -C*y[1]*y[2]+E*y[0]*y[1];
  f[2] = B*y[0]*y[2]+C*y[1]*y[2]-A*y[1]*y[2];
  return GSL_SUCCESS;
}
