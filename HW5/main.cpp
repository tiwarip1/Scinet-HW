#include <iostream>
#include <cmath>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>

#include "function.h"
#include "jacobian.h"

using namespace std;
//This function does the calculation, where it goes through the differential equation given a number of zombies
int calculation(int Z0){
  //Defining all the static variables
  float B = 0.02;
  float E = 0.015;
  float A = 0.03;
  float C = 0.01;
  int K0 = 9;
  int S0 = 500-K0-Z0;
  //S=0, K=1, Z=2

  int i;
  double t=0.0, t1=100.0;

  
    double param[4] = {.03,.02,.01,.015};
    double y[3] = { S0, K0 , Z0 };//Define the array of survivors and zombies

    gsl_odeiv2_system system = {function,jacobian,3,&param};//Defining our system to GSL

  gsl_odeiv2_driver * d =
    gsl_odeiv2_driver_alloc_y_new (&system, gsl_odeiv2_step_rk8pd,
                                   1e-6, 1e-6, 0.0);//Using a specific driver to iterate and solve out equations

  for (i = 1; i <= 40; i++)
    {
      double ti = i * t1 / 40.0;
      int status = gsl_odeiv2_driver_apply (d, &t, ti, y);//Actually using the drivers

      if (status != GSL_SUCCESS)//Checks to make sure everything's fine
        {
          printf ("error, return value=%d\n", status);
          break;
        }

      printf ("%.5e %.5e %.5e %.5e\n", t, round(y[0]), round(y[1]), round(y[2]));//Used for outputting
    }
 
  cout<<endl;
  gsl_odeiv2_driver_free (d);//Free up the driver

  return 0;

}

int main(){

  calculation(7);//Zombies lose
  calculation(8);//Zombies win

  return 0;

}
