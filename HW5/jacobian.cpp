#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

#include "jacobian.h"

int
jacobian (double t, const double y[], double *dfdy,
	  double dfdt[], void *params)
{
  (void)(t); /* avoid unused parameter warning */
  double mu = *(double *)params;
  float B = 0.02;
  float E = 0.015;
  float A = 0.03;
  float C = 0.01;
  gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 3, 3);
  gsl_matrix * m = &dfdy_mat.matrix;
  gsl_matrix_set (m, 0, 0, -B*y[2]-E*y[1]);
  gsl_matrix_set (m, 0, 1, -E*y[0]);
  gsl_matrix_set (m, 0, 2, -B*y[0]);
  gsl_matrix_set (m, 1, 0, E*y[1]);
  gsl_matrix_set (m, 1, 1, -C*y[2]+E*y[0]);
  gsl_matrix_set (m, 1, 2, -C*y[1]);
  gsl_matrix_set (m, 2, 0, B*y[2]);
  gsl_matrix_set (m, 2, 1, C*y[2]-A*y[2]);
  gsl_matrix_set (m, 2, 2, B*y[0]+C*y[1]-A*y[1]);
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  dfdt[2]=0.0;
  return GSL_SUCCESS;
}
