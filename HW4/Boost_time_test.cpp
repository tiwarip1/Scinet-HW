#include <iostream>
using std::cout;using std::endl;
#include <rarray>
#include <string>
using std::string;

#include "timestep.h"

#define BOOST_TEST_TIME
#define BOOST_TEST_MODULE BOOST_TIME_TEST

#include <boost/test/unit_test.hpp>
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(timetest){

//Random values and empty arrays
	int total_ants = 100;
	int length=20;
	rarray<int,2> number_of_ants(length,length);
	rarray<int,2> new_number_of_ants(length,length);
	size_t seed=1;

	//Makes the random distribution that was tested
	initialize_uniform(number_of_ants, total_ants);

	//Goes through a single timestep
	perform_one_timestep(number_of_ants,new_number_of_ants,seed);
	
	//Makes sure the number of ants after a time step is less than or equal to the number of ants it started with
	int counter=0;
	for (size_t i = 0; i<length;i++){
		for (size_t j = 0; j<length;j++){
		
			counter+=new_number_of_ants[i][j];
		
		}
	}
	
	BOOST_CHECK(counter==total_ants||counter<total_ants)
  
}
