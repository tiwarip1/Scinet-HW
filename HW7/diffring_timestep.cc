// 
// diffring_timestep.cc
//
// Time step module for 1d diffusion on a ring
//

#include "diffring_timestep.h"
#include <cblas.h>
#include <cmath>
#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

using namespace std;

// perform a single time step for the random walkers
void diffring_timestep(const rarray<double,2>& F, rarray<double,1>& P)
{
  //Take in parameters
  boost::property_tree::ptree pt;
  boost::property_tree::ini_parser::read_ini("params.ini", pt);
  double D = pt.get<double>("Params.D");
  double dt = pt.get<double>("Params.dt");
  double dx = pt.get<double>("Params.dx");
  double T = pt.get<double>("Params.T");
  //Max size to iterate over
  size_t max_size = F[0].size();
  //arrays of derivatives in diffusion equation
  rarray<double,1> dx2(max_size);
  rarray<double,1> time_deriv(max_size);
  //Iterate over density array
  for(size_t i = 0; i < P.size() ; i++ ){

    size_t i_minus_1;
    size_t i_plus_1;
    //This section was to impose the rolling boundary conditions
    if(i-1 < 0){
      i_minus_1 = max_size;
      i_plus_1 = i+1;
    }
    else if(i+1==max_size){
      i_plus_1 = 0;
      i_minus_1 = i-1;
    }
    else{
      i_minus_1 = i - 1;
      i_plus_1 = i+1;
    }
    //Calculate the derivatives
    double numerator = P[i_plus_1]-2*P[i]+P[i_minus_1];
    dx2[i]=numerator/(dx*dx);
    time_deriv[i]=(1+dt*D)*dx2[i];
  }

  for(size_t i=0;i<max_size;i++){
    //Uses the time derivative to determine the next density array after dt
    P[i]+=time_deriv[i]*dt;

  }

}

// fill the matrix needed in perform_time_step
void diffring_fill_timestep_matrix(rarray<double,2>& F, double D, double dt, double dx)
{

  F[0]=1.0;
  

}
