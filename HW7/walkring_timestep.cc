// 
// walkring_timestep.cc
//
// Time stepping module for 1d random walk on a ring
//

#include "walkring_timestep.h"
#include <random>
#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

using namespace std;

// Perform a single time step for the random walkers
//
// parameters:
//
//  walkerpositions: the positions of a number of walkers (note that
//                   the number of walker Z can be found from
//                   Z=walkerpositions.size())
//
//  N:               the number of possible positions. All positions
//                   in the walkerpositions array should remain
//                   between 0 and N-1
//
//  prob:            the probability to jump to the left. Also the
//                   probability to just right.  (the probability to
//                   stay on the same spot is thus 1-2p.)
//
// output:
//
//  the content of the walkerpositions arrays should have changed to
//  reflect the random movement of all walker (i.e., they will each
//  have been given a chance to move on position to the left or two
//  the right).
//
void walkring_timestep(rarray<int,1>& walkerpositions, int N, double prob)
{
  //Define parameters
  boost::property_tree::ptree pt;
  boost::property_tree::ini_parser::read_ini("params.ini", pt);
  double D = pt.get<double>("Params.D");
  double walkers = pt.get<double>("Params.walkers");
  double dx = pt.get<double>("Params.dx");
  double T = pt.get<double>("Params.T");
  for(size_t i=0; i<walkerpositions.size();i++){
    
    size_t i_minus_1;
    size_t i_plus_1;
    size_t max_size=walkerpositions.size();
    //Impose rolling boundary conditions
    if(i<=0){
      i_minus_1=max_size-1;
      i_plus_1=i+1;
    }
    else if(i+1>=max_size-1){
      i_minus_1=i-1;
      i_plus_1=0;
    }
    else{
      i_minus_1=i-1;
      i_plus_1=i+1;
    }
    //Determine how many move left or right
    int move_left = 0;
    int move_right = 0;

    for(int j=0; j<walkerpositions[i];j++){
      //random number and compare with the probability of moving left or right
      double r = ((double) rand() / (RAND_MAX));
      
      if(r<prob){
	move_left++;
      }
      else if(1-r<prob){
	move_right++;
      }
      
    }
    //Move the agents between squares if told to move
    walkerpositions[i_minus_1]+=move_left;
    walkerpositions[i_plus_1]+=move_right;
    walkerpositions[i]-=(move_left+move_right);

  }
}


