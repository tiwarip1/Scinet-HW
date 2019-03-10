#include <iostream>
#include <string>
#include <../../OpenBLAS/cblas.h>
#include <sstream>
#include <cmath>
#include <vector>

#include "power_spectrum.h"
#include "read_file.h"

using namespace std;
//Finds correlation and sends that to main using two files
double do_the_thing(string file1,string file2){
  
  //Does the fft from the file
  rarray<std::complex<double>,1> fft1 = read_file(file1);
  rarray<std::complex<double>,1> fft2 = read_file(file2);

  const rarray<double,1> power1(power_spectrum(fft1));
  const rarray<double,1> power2(power_spectrum(fft2));
  int unity = 1;
  int dimension = fft1.size();

  //std::cout<<dimension<<" "<<sizeof(power1)/sizeof(*power1)<<endl;
  //double correlation_f_g[dimension];
  
  //std::cout<<"doing correlation"<<std::endl;
  double correlation_f_g = cblas_ddot(dimension,power1.data(),unity,power2.data(),unity);
  //std::cout<<"Done correlation"<<std::endl;
  
  //cout<<correlation_f_g<<endl;

  double correlation_f_f = cblas_ddot(dimension,power1.data(),unity,power1.data(),unity);

  double correlation_g_g = cblas_ddot(dimension,power2.data(),unity,power2.data(),unity);

  double total_correlation = correlation_f_g/std::pow(correlation_f_f*correlation_g_g,.5);

  //cout<<"all good"<<endl;

  return total_correlation;
}

int main(){
  //Location of files and file types
  string prefix = "data/detection";
  string suffix = ".nc";
  //Leaderboard for top 5 correlations, they will fight it out
  vector<double> first = {-1,-1,-1};
  vector<double> second = {-2,-2,-2};
  vector<double> third = {-3,-3,-3};
  vector<double> fourth = {-4,-4,-4};
  vector<double> fifth = {-5,-5,-5};
  //Iterate over the number of files we are looking at
  for(int i=1;i<33;i++){
    
    for(int j=1;j<33;j++){
      //Using ostringstream to put the integers and strings together
      ostringstream oss1;
      ostringstream oss2;
      //Don't want to double count
      if(i==j || j<i){ continue; }
      //This is some organizational stuff
      if(i<10 && j<10){

	oss1<<prefix<<"0"<<i<<suffix;
	oss2<<prefix<<"0"<<j<<suffix;

      }
      else if(i<10 && j>9){
      
	oss1<<prefix<<"0"<<i<<suffix;
	oss2<<prefix<<j<<suffix;

      }
      else if(j<10 && i>9){

	oss1<<prefix<<i<<suffix;
	oss2<<prefix<<"0"<<j<<suffix;

      }
      else{

	oss1<<prefix<<i<<suffix;
	oss2<<prefix<<j<<suffix;
      }
      //cout<<oss1.str()<<"    "<<oss2.str()<<endl;
      double correlation = do_the_thing(oss1.str(),oss2.str());
      //std::cout<<"Correlation for "<<i<<" and "<<j<<" are: "<<correlation<<std::endl;
      //We have a new correlation leader
      if(correlation>first[2]){
	fifth = fourth;
	fourth=third;
	third=second;
	second=first;
	first={static_cast<double>(i),static_cast<double>(j),correlation};
	}

    }
  }
  //Tells the people what they want to hear
  cout<<"Here are the top 5 correlations between files"<<endl;
  cout<<"Correlation of "<<first[2]<<" between "<<first[0]<<" and "<<first[1]<<endl;
  cout<<"Correlation of "<<second[2]<<" between "<<second[0]<<" and "<<second[1]<<endl;
  cout<<"Correlation of "<<third[2]<<" between "<<third[0]<<" and "<<third[1]<<endl;
  cout<<"Correlation of "<<fourth[2]<<" between "<<fourth[0]<<" and "<<fourth[1]<<endl;
  cout<<"Correlation of "<<fifth[2]<<" between "<<fifth[0]<<" and "<<fifth[1]<<endl;

  return 0;
}
