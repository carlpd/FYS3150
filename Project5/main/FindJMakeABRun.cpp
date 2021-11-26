#include "../hpp/FindJMakeAB.hpp"
#include <iostream>
int main(){
  arma::cx_mat A=arma::cx_mat(9,9).fill(0.);
  arma::cx_mat B=arma::cx_mat(9,9).fill(0.);
  arma::cx_vec a=arma::cx_vec(9).fill(4.);
  arma::cx_vec b=arma::cx_vec(9).fill(-4.);
  arma::cx_double r=(-1,1);
  MakeABC(A, B, a, b, r);
  std::cout<<A<<std::endl;
  return 0;
}
