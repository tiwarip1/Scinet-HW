#include <iostream>
using std::cout;using std::endl;
#include <rarray>
#include <string>
using std::string;

#include "randompartition.h"

#define BOOST_TEST_RAND
#define BOOST_TEST_MODULE Boost_init_test

#include <boost/test/unit_test.hpp>
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(randtest){

  //Given some random values and an empty array
  int total=100;
  int regions=10;
  rarray<int,1> possible_numbers (regions);
  size_t seed = 1;
  int failures=0;//This variable is a counter as to how many time the randomization procedure failed

  //The function loops over 10 different seeds and puts that into the randomization function
  //which then checks to make sure the randomizor didn't lose any information
  for(size_t seed=0;seed<regions;seed++){
    rand_partition(total,regions,possible_numbers,seed);
    
    int counter=0;
    for(size_t i = 0; i<regions;i++){
      counter+=possible_numbers[i];
    }
    
    if (counter!=100){
      failures++;
    }
  }
  BOOST_CHECK(failures==0);
  
}
