//This file is make to culminate all the tests that we want to do on
//the separate files

#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <random>
#include <algorithm>

#include "timestep.h"
#include "randompartition.h"
#include "init_test.h"

void init_testing();
void rand_testing();
void time_testing();

int main(){
	
	init_testing();
	rand_testing();
	time_testing();
	
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

void time_testing(){
	
	cout<<"Testing the timestep functionality"<<endl;
	
	int total_ants = 100;
	int length=20;
	rarray<int,2> number_of_ants(length,length);
	rarray<int,2> new_number_of_ants(length,length);
	size_t seed=1;
	
	initialize_uniform(number_of_ants, total_ants);
	
	perform_one_timestep(number_of_ants,new_number_of_ants,seed);
	
	int counter=0;
	for (size_t i = 0; i<length;i++){
		for (size_t j = 0; j<length;j++){
		
			counter+=new_number_of_ants[i][j];
		
		}
	}
	
	if (counter==total_ants || counter<total_ants){
		
		cout<<"The timestep function's good"<<endl;
		
	}
	else{
		
		cout<<"We got a big problem in the timestep function"<<endl;
	
	}


}
