#include "../hpp/AllFunks.hpp"

int main(){
  arma::sp_cx_mat A=arma::sp_cx_mat(9,9);
  arma::sp_cx_mat B=arma::sp_cx_mat(9,9);
  arma::cx_vec a=arma::cx_vec(9).fill(4.);
  arma::cx_vec b=arma::cx_vec(9).fill(-4.);
  arma::cx_double r=(-1,1);
  MakeAB(A, B, a, b, r);
  std::cout<<A<<std::endl;
  arma::cx_vec u=arma::cx_vec(9).fill(5.);
  arma::cx_vec bn=findb(B,u);
  arma::cx_vec un=(A,bn);
  std::cout<<un<<std::endl;
  return 0;
}
