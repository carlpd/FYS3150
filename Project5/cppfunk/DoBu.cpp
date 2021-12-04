#include "../hpp/DoBu.hpp"

arma::cx_vec findb(arma::sp_cx_mat B, arma::cx_vec u){
  int lu=u.n_elem;
  arma::cx_vec u_n=B*u;
  return u_n;
}
arma::cx_vec findu_new(arma::sp_cx_mat A, arma::cx_vec b){
  arma::cx_vec u_new=arma::spsolve(A,b);
  return u_new;
}
