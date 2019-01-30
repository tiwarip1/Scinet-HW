#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;
#include <rarray>

//Creates the ants on a table by filling in the rarray number_of_ants, then returns
//that rarray
rarray<int,2> init(int length, int total_ants, rarray<int,2> number_of_ants) {

	// place the ants evenly on the tabley
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			int n = i * length + j; // linear index
			number_of_ants[i][j] = ((long long)(n + 1)*total_ants) / (length*length) - ((long long)(n)*total_ants) / (length*length);
		}
	}

	return number_of_ants;
}
