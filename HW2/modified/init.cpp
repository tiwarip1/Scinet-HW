#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;

//Creates the ants on a table by filling in the array number_of_ants, then returns
//that array
int *init(int length, int total_ants, int* number_of_ants) {

	// place the ants evenly on the table
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			int n = i * length + j; // linear index
			number_of_ants[n] = ((long long)(n + 1)*total_ants) / (length*length) - ((long long)(n)*total_ants) / (length*length);
		}
	}

	return number_of_ants;
}