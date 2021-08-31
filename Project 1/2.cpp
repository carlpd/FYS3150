#include <iostream>
#include "2.hpp"
#include <cmath>
#include<fstream>
#include<string>
double u(double y){
  return 1-(1-exp(-10))*y-exp(-10*y);
}

int main(){
  //double x[100];
  double h = 1.0/n;
  std::fstream ofile;
  ofile.open("2tekst.txt");
  ofile.clear();
  for (int i=0; i<n;i++){
    x[i]=i*h;
    double uu=u(x[i]);
    ofile << x[i] << " "<< uu << std::endl;
  }
  x[n]=1.0;
  ofile << x[n] << " " << u(x[n]) << std::endl;
  ofile.close();
  return 0;
}
