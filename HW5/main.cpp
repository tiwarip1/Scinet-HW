#include <iostream>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>

#include "function.h"
#include "jacobian.h"

int main(){
  //Defining all the static variables
  float B = 0.02;
  float E = 0.015;
  float A = 0.03;
  float C = 0.01;
  int K0 = 9;
  int Z0 = 5;
  int S0 = 500-K0-Z0;
  //S=0, K=1, Z=2
  gsl_odeiv2_system system = {function,jacobian,3,&K0};

  gsl_odeiv2_driver * d =
    gsl_odeiv2_driver_alloc_y_new (&system, gsl_odeiv2_step_rk8pd,
				   1e-6, 1e-6, 0.0);

  int i;
  double t = 0.0, t1 = 100.0;
  double y[3] = { S0, K0 , Z0 };

  for (i = 1; i <= 100; i++)
    {
      double ti = i * t1 / 100.0;
      int status = gsl_odeiv2_driver_apply (d, &t, ti, y);

      if (status != GSL_SUCCESS)
        {
          printf ("error, return value=%d\n", status);
          break;
        }

      printf ("%.5e %.5e %.5e %.5e\n", t, y[0], y[1], y[2]);
    }

  gsl_odeiv2_driver_free (d);
  return 0;

}
