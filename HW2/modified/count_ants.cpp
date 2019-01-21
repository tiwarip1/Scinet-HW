#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;

//This function takes a set of arguments and goes throught he number_of_ants
//to find the total number of ants, the min and max on a single sector and outputs
//them to a vector of ints and that is what is returned
vector<int> count_ants(int length, int total_ants, int* number_of_ants,bool output) {
	// count ants and determine minimum and maximum number on a square
	int nmin = total_ants;
	int nmax = 0;
	total_ants = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			int n = i * length + j; // linear index
			total_ants += number_of_ants[n];
			if (nmin > number_of_ants[n]) {
				nmin = number_of_ants[n];
			}
			if (nmax < number_of_ants[n]) {
				nmax = number_of_ants[n];
			}
		}
	}

	if (output){
		// report if the function is prompted to print the output
		std::cout << 0 << " " << total_ants << " " << nmin << " " << nmax << std::endl;
	}

	vector<int> counted_variables = { nmin,nmax,total_ants };

	return counted_variables;
}