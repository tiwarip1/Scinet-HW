//This file is used to test the initialization.cc file, by taking 5 test
//cases with different given tables to check accuracy

#include "init_test.h"
#include "initialization.h"
#include "report.h"

#include <rarray>
//This function was supposed to be used by the boost files, but I can't get it to work
int variable_testing(int total_ants,int length){
  //Define an array taht we will pass into the initialization function
	rarray<int,2> number_of_ants(length,length);
	
	initialize_uniform(number_of_ants, total_ants);
	//Get a summary to make sure nothing went wrong while we made the distribution
	total_ants = report_summary(number_of_ants, 0);
	
	return total_ants;
	
}

void initial_test(){
	
	int total_ants = 100;
	int length=20;
	rarray<int,2> number_of_ants(length,length);
	
	initialize_uniform(number_of_ants, total_ants);
	
	total_ants = report_summary(number_of_ants, 0);
	
}

void large_limit_test(){
  //Run into an error above 10000000
	int total_ants = 1000000;
	//Apparently we run into an error using length=20000
	int length=2000;
	rarray<int,2> number_of_ants(length,length);
	
	initialize_uniform(number_of_ants, total_ants);
	
	total_ants = report_summary(number_of_ants, 0);
}

void small_limit_test(){
	
  //This works out well, as we see the average number of ants in each square is just total_ants/length^2
	int total_ants = 1000;
	int length=2;
	rarray<int,2> number_of_ants(length,length);
	
	initialize_uniform(number_of_ants, total_ants);
	
	total_ants = report_summary(number_of_ants, 0);
	
}
//We run into an error with this, so it can't handle negatives
void negative_test(){
	
	int total_ants = -100;
	int length=-20;
	rarray<int,2> number_of_ants(length,length);
	
	initialize_uniform(number_of_ants, total_ants);
	
	total_ants = report_summary(number_of_ants, 0);
	
}

void mid_range_test(){
	
	int total_ants = 10000;
	int length= 20;
	rarray<int,2> number_of_ants(length,length);
	
	initialize_uniform(number_of_ants, total_ants);
	
	total_ants = report_summary(number_of_ants, 0);
	
}

