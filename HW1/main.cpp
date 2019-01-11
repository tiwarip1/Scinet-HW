#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <cmath>
using std::cos;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream; //Using ostringstream for debugging
#include <fstream>
using std::ofstream;

double f(double x);// Defining all the functions other than main
double g(double x);

int main() {

	ostringstream oss;//Using to culminate all the values to be written

	for (double i = -5; i <= 5; i += .1) {//loop from -5 to 5

		oss << i <<" "<< f(i) << " " << g(i) << endl;

	}

	//cout << oss.str() << endl; // Printing to check
	
	ofstream myfile;

	myfile.open("pranjaltiwari.txt");

	myfile << oss.str();

	myfile.close();

	return 0;

}

double f(double x) {

	return sin(2 * x);

}

double g(double x) {

	return cos(3 * x);

}
