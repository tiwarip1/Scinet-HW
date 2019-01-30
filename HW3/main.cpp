
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;
#include <rarray>
#include <netcdf>
using namespace netCDF;
using namespace netCDF::exceptions;
#include "init.h"
#include "Randpartition.h"
#include "count_ants.h"
#include "run.h"
using namespace std;
// Main driver
int main()
{
  static const int NC_ERR = 2;
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
	rarray<int,2> number_of_ants(length,length);
	rarray<int,2> new_number_of_ants(length,length);
	//int *number_of_ants = new int[length*length];     // distribution of ants on the table over squares.
	//int *new_number_of_ants = new int[length*length]; // auxiliary array used in time step to hold the new distribution of ants
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
	
	
	
	vector<int> tp1;
	vector<int> nmin_l;
	vector<int> nmax_l;
	vector<int> total_ants_l;
	
	int total_t=0;

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
		
		tp1.push_back(t+1);
		nmin_l.push_back(nmin);
		nmax_l.push_back(nmax);
		total_ants_l.push_back(total_ants);
		
		total_t = t;

	}
	
	int everything[4][total_t];
	
	for (int i=0;i<4;i++){
	  for (int j=0;j<total_t;j++){
			
			if(i==0){
				everything[i][j]=tp1[j];
			}
			else if(i==1){
				everything[i][j]=nmin_l[j];
			}
			else if(i==2){
				everything[i][j]=nmax_l[j];
			}
			else if(i==3){
				everything[i][j]=total_ants_l[j];
			}
		}
	}

	NcFile dataFile("output.nc",NcFile::replace);
	
	NcDim tDim = dataFile.addDim("t+1",total_t);
	NcDim nminDim = dataFile.addDim("nmin",total_t);
	NcDim nmaxDim = dataFile.addDim("nmax",total_t);
	NcDim totalDim = dataFile.addDim("total_ants",total_t);
	std::vector<NcDim> dims(4);
	
	dims[0] = tDim;
	dims[1] = nminDim;
	dims[2] = nmaxDim;
	dims[3] = totalDim;
	
	NcVar data = dataFile.addVar("data",ncInt,dims);

	data.putVar(&everything);
	
	return 0;
}

