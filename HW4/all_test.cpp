//This file is make to culminate all the tests that we want to do on
//the separate files

#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

#include "init_test.h"

int main(){
	
	cout<<"Testing initialization of the table"<<endl;
	
	//Just an initial test to make sure there are no errors
	initial_test();
	
	//Testing how the program deals with large ant and square numbers
	large_limit_test();
	
	//Too many ants for too few squares
	small_limit_test();
	
	//negative_test(); //this test throws an error
	
	//Just a mid range test of the board
	mid_range_test();
	
	
}
