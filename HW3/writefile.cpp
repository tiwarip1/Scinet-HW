#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::vector;
#include <rarray>
#include <netcdf>
using namespace netCDF;

void writing(int total_t,rarray<float,1> t_values, rarray<float,1> nmin_values,
rarray<float,1> nmax_values, rarray<float,1> total_values){
	
	//Create netCDF file
	NcFile dataFile("output.nc",NcFile::replace);
	
	//Define column names
	NcDim tDim = dataFile.addDim("t+1");
	NcDim nminDim = dataFile.addDim("nmin",total_t);
	NcDim nmaxDim = dataFile.addDim("nmax",total_t);
	NcDim totalDim = dataFile.addDim("total_ants",total_t);
	
	//And put all that information into a netCDF file at the very end
	NcVar ts = dataFile.addVar("t",ncFloat,tDim);
	NcVar nmins = dataFile.addVar("nmin",ncFloat,nminDim);
	NcVar nmaxs = dataFile.addVar("nmax",ncFloat,nmaxDim);
	NcVar totals = dataFile.addVar("total_ants",ncFloat,totalDim);
	
	std::vector<NcDim> dims(4);
	
	//Put these column names into a vector
	dims[0] = tDim;
	dims[1] = nminDim;
	dims[2] = nmaxDim;
	dims[3] = totalDim;

	ts.putVar(t_values.data());
	nmins.putVar(nmin_values.data());
	nmaxs.putVar(nmax_values.data());
	totals.putVar(total_values.data());
	
}
