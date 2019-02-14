#include <iostream>
using std::cout;using std::endl;
#include <rarray>
#include <string>
using std::String;

#include "init_test.h"

#define BOOST_TEST_INIT
#define BOOST_TEST_MODULE output_bt

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(variable_testing){
	
	normal_limit = variable_testing(100,20);
	large_limit = variable_testing(100000,2000);
	small_limit = variable_testing(1000,2);
	mid_limit = variable_testing(10000,200);
	singular = variable_testing(1,1);
	
	BOOST_CHECK(normal_limit==100&&large_limit==100000&&small_limit==1000&&mid_limit==10000&&sinular==1);
}
