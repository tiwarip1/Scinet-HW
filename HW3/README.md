In this homework, we had to use the ants on the table code from the last homework. We had to add a module that appends values to a netCDF file every 1000 timesteps.

The new module that does this is the writefile.cpp file. The makefile needed to be modified to include a clean command and account for the new module. Comments are present in main.cpp and writefile.cpp

We also had to replace the 2d dynamically allocated arrays with 2d rarrays aswell, which required small modifications of the .h and .cpp files to work with the new type.