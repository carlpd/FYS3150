#include <iostream>
#include <armadillo>
#include <complex>

using namespace std::complex_literals;


int FindK(int i, int j, int M);
//void MakeAB(arma::cx_mat& A, arma::cx_mat& B, arma::cx_vec a, arma::cx_vec b, arma::cx_double r);
void MakeAB(arma::sp_cx_mat& A,  arma::sp_cx_mat& B, arma::cx_vec a, arma::cx_vec b, arma::cx_double r);
arma::cx_vec findb(arma::sp_cx_mat B, arma::cx_vec u);
arma::cx_vec findu_new(arma::sp_cx_mat A, arma::cx_vec b);
arma::cx_double makegaus(arma::cx_double x, double sig, double mu, double kx);
arma::cx_vec makeinit(int size, double sigx, double sigy, double mux, double muy, double kx, double ky);
arma::vec findWall(int sl);
arma::vec makeV(int sz, int sl);
arma::cx_vec makea(int sz, arma::vec v, arma::cx_double r, double dt);
arma::cx_vec makeb(int sz, arma::vec v, arma::cx_double r, double dt);
double FindP(arma::cx_vec u);
arma::cx_mat BackToMat(arma::cx_vec u);
arma::mat BackToRealMat(arma::vec u);
