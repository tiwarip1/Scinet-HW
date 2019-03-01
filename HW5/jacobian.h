#ifndef JACOBIAN
#define JACOBIAN

#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

int
jacobian (double t, const double y[], double *dfdy,
	  double dfdt[], void *params);

#endif
