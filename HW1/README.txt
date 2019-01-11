I wrote and complied this in visual studio 2017. How this program works is, when run, the main function will begin by doing
a for loop from -5 to 5 inclusive of either end. During this time, the function calls two other function "f" and "g", which
return either sin or cos of the value given to them, which is a double. Then these are passed to an ostringstream object,
at the end of the loop the ostringstream object is turned into a string and outputted to a text file using ofstream