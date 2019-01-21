#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;

#include "count_ants.h"
#include "Randpartition.h"

int* run_once(int length, int* new_number_of_ants, int* number_of_ants, int nmoves,size_t seed, int* partition,const int* jmoves, const int* imoves, int total_ants, int nmin, int nmax, int t) {

	// ants move to a new an auxiliary new 'table', empty this one first
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			int n = i * length + j; // linear index
			new_number_of_ants[n] = 0;
		}
	}

	// now move ants into auxiliary table
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			int n = i * length + j; // linear index
			if (number_of_ants[n] > 0) {
				// pick how many ants go in each of the 9 moves
				rand_partition(number_of_ants[n], nmoves, partition, seed);
				// push ants in their respective moves 
				for (int m = 0; m < nmoves; m++) {
					int i2 = i + imoves[m];
					int j2 = j + jmoves[m];
					// put only on new table if not falling off table
					if (i2 >= 0 and i2 < length and j2 >= 0 and j2 < length) {
						int n = i2 * length + j2; // linear index
						new_number_of_ants[n] += partition[m];
					}
				}
			}
		}
	}

	// update number_of_ants
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			int n = i * length + j; // linear index
			number_of_ants[n] = new_number_of_ants[n];
		}
	}

	vector<int> counted_variables = count_ants(length, total_ants, number_of_ants,false);

	//Separating those ints in the vector to their respective variable name
	nmin = counted_variables[0];
	nmax = counted_variables[1];
	total_ants = counted_variables[2];

	// report
	std::cout << t + 1 << " " << total_ants << " " << nmin << " " << nmax << std::endl;

	return new_number_of_ants;

}