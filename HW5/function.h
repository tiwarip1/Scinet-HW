#ifndef FUNCTION
#define FUNCTION

#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

int function(double t, const double y[], double f[],
	     void *params);

#endif
