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

double f(double x);
double g(double x);

int main(){

  ostringstream oss;
  
  for(double i=-5;i<=5;i+=.1){

    oss<<f(i)<<" "<<g(i)<<endl;
    
  }

  cout<<oss.str()<<endl;
  
  return 0;
  
}

double f(double x){

  return sin(2*x);
  
}

double g(double x){

  return cos(3*x);
  
}
