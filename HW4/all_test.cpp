//This file is make to culminate all the tests that we want to do on
//the separate files

#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <random>
#include <algorithm>

#include "randompartition.h"
#include "init_test.h"

void init_testing();
void rand_testing();

int main(){
	
	init_testing();
	rand_testing();
	
}

void init_testing(){
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
	
	cout<<"Everything looks good"<<endl;
}

void rand_testing(){
	
	cout<<"Testing the randomization function"<<endl;
	
	int total=100;
	int regions=10;
	rarray<int,1> possible_numbers (regions);
	size_t seed = 1;
	for(size_t seed=0;seed<regions;seed++){
		rand_partition(total,regions,possible_numbers,seed);
		
		int counter=0;
		for(size_t i = 0; i<regions;i++){
			counter+=possible_numbers[i];
		}
		
		if (counter==100){
			cout<<"Successfully randomized a distribution"<<endl;
		}
	}
	cout<<"Finished Testing randomization function, looks good"<<endl;
	
}
