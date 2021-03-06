
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;

#include "init.h"
#include "Randpartition.h"
#include "count_ants.h"
#include "run.h"

// Main driver
int main()
{
	//Moved global variables to being within the main function
	const int nmoves = 9; // There are (3 in the i direction)x(3 in the j direction)=9 possible moves

	const int imoves[] = { -1,-1,-1, 0, 0, 0, 1, 1, 1 }; // Effect of each move on the i direction
	const int jmoves[] = { -1, 0, 1,-1, 0, 1,-1, 0, 1 }; // Effect of each move on the j direction

	// defines parameters that would have been more a hassle to do in init.cpp
	int    length = 70;     // length of the table
	int    time_steps = 10000;  // number of time steps to take
	int    total_ants = 40000;  // initial number of ants
	size_t seed = 11;     // seed for random number generation

						  // work arrays
	int *number_of_ants = new int[length*length];     // distribution of ants on the table over squares.
	int *new_number_of_ants = new int[length*length]; // auxiliary array used in time step to hold the new distribution of ants
	int *partition = new int[nmoves];                 // used to determine how many ants move in which direction in a time step
	int nmin = total_ants;                 // will hold the minimum number of ants on any square
	int nmax = 0;                          // will hold the maximum number of ants on any square                        

	//Initializes the ants on the table
	number_of_ants = init(length, total_ants, number_of_ants);

	//Calling a function that counts all the ants that are in the array number_of_ants and finds the max in a square and min along
	//with the total and outputs a vector of ints that contains those values
	vector<int> counted_variables = count_ants(length, total_ants, number_of_ants,false);
	
	//Separating those ints in the vector to their respective variable name
	nmin = counted_variables[0];
	nmax = counted_variables[1];
	total_ants = counted_variables[2];

	// run time steps
	for (int t = 0; t < time_steps; t++) {
		
		//Everytime the program is run, it take a function from run.h and updates
		//the necessary variables every time, more info on the other .cpp file
		new_number_of_ants = run_once(length, new_number_of_ants, number_of_ants, nmoves, seed, partition, jmoves, imoves, total_ants, nmin, nmax, t);
		
		//Refinds the variables of ants on the table
		vector<int> counted_variables = count_ants(length, total_ants, number_of_ants,false);

		nmin = counted_variables[0];
		nmax = counted_variables[1];
		total_ants = counted_variables[2];

	}
	return 0;
}

