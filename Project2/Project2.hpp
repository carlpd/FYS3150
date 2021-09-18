#include <iostream>
#include <armadillo>
#include <stdexcept>
#include <cmath>
double max_offdiag_symmetric(arma::mat& A, int& k, int& l);
void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l);
void jacobi_eigensolver(arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations, bool& converged);
