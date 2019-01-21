// antsontable.cc
//
// Simulation of ants walking on a table. The table is subdivided into
// squares. A number of ants is initially put on the table, divided as
// evenly as possible over the squares.  Ants can move to a
// neighbouring square or stay put at every time step.  How many of a
// square's ants move in each of the 9 different directions is random
// (using c++11's random library).  Ants can fall of the edges of the
// table. The program prints the number of ants left on the table
// after every time step, as well as the minimum number of ants on a
// square and the maximum.
//
// This is the code for assignment 2 for the scientific computing course
// PHY1610H given in the Winter of 2019.
//
// Compile with:
//
//     g++ -std=c++11 -O3 -march=native -o antsontable antsontable.cc 
//  
// On the clusters, it will be necessary to load the "gcc" module first.
//
// Run with
//
//     ./antsontable > output.dat
//
// This saves the output to the file output.dat instead of writing it to
// screen.
//
// Ramses van Zon, SciNet, University of Toronto
// January 2019

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;

#include "init.h"
#include "Randpartition.h"
#include "count_ants.h"
#include "run.h"

const int nmoves = 9; // There are (3 in the i direction)x(3 in the j direction)=9 possible moves

const int imoves[] = { -1,-1,-1, 0, 0, 0, 1, 1, 1 }; // Effect of each move on the i direction
const int jmoves[] = { -1, 0, 1,-1, 0, 1,-1, 0, 1 }; // Effect of each move on the j direction

														   // Function to randomly divide a number 'total' into a set of
														   // 'numdivision' numbers that add up to 'total'.
														   //
														   // Parameters:
														   //   total     number that is to be subdivided (input)
														   //   nparts    number of partitions into which to divide 'total (input)
														   //   nperpart  resulting number in each partition (output)
														   //   seed      the seed for the random number generator (input)
														   //

// Main driver function of antsontable.cc
int main()
{
	// parameters
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

		new_number_of_ants = run_once(length, new_number_of_ants, number_of_ants, nmoves, seed, partition, jmoves, imoves, total_ants, nmin, nmax, t);
		
		vector<int> counted_variables = count_ants(length, total_ants, number_of_ants,false);

		//Separating those ints in the vector to their respective variable name
		nmin = counted_variables[0];
		nmax = counted_variables[1];
		total_ants = counted_variables[2];

	}
	return 0;
}

