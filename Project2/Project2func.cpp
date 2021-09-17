#include "Project2.hpp"

double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){
  if (A.is_square() == false){
    throw std::invalid_argument("A not a square matrix");
  }
  int rows = A.n_rows;
  if (rows < 2){
    throw std::invalid_argument("A must be larger than 1x1");
  }
  double current_highest = 0.;
  //Tester kun for den øvre delen av diagonalen siden A er symmetrisk
  //Vil si at i går gjennom alle kolonner
  //Og at j går fra den kolonnens diagonalelement og utover
  for (int i = 0; i < rows; i++){
    for (int j = i+1; j < rows; j++){
      //Matrisene henter element row-col så blir omvendt av for-løkkene
      double element = std::abs(A(i,j));
      if ((element > std::abs(current_highest))==1){
        current_highest = A(i, j);
        //Setter rad-nummeret til k og kolonnenummeret til l
        k = i;
        l = j;
      }
    }
  }
  return current_highest;
}
// Performs a single Jacobi rotation, to "rotate away"
// the off-diagonal element at A(k,l).
// - Assumes symmetric matrix, so we only consider k < l
// - Modifies the input matrices A and R
void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l){
  //std::cout<<"Starting"<<std::endl;
  //Regner ut tau som definert i kompendiet.
  double tau = (A(l,l)-A(k,k))/(2*A(k,l));
  //t = tan theta (choosing smallest), s = sin theta, c = cos theta
  double tm = -tau- std::sqrt(1+std::pow(tau, 2));
  double tp = -tau + std::sqrt(1+std::pow(tau,2));
  double t;
  if (tau>=0){
    t=1/(tau*sqrt(tau*tau+1));
  }
  if (tau<0){
    t=1/(-tau+sqrt(tau*tau+1));
  }
  double c=1/sqrt(1+t*t);
  double s=c*t;
  //std::cout<<"Starting transform"<<std::endl;
  //Tranformerer A(m) til A(m+1)
  A(k,k)=A(k,k)*c*c+2*A(k,l)*c*s+A(l,l)*s*s;
  A(l,l)=A(l,l)*c*c+2*A(k,l)*c*s+A(k,k)*s*s;
  for(int i=0;i<A.n_rows;i++){
    if (i!=l && i!=k){
      double aik=A(i,k); //lagrer for to linjer under
      A(i,k)=A(i,k)*c-A(i,k)*s;
      A(k,i)=A(i,k);
      A(l,i)=A(i,l)*c+aik*s;
      A(l,i)=A(i,l);
    }
  }
  //std::cout<<"Went thorugh transform"<<std::endl;
  //Oppdaterer R
  for(int i=0; i<A.n_rows; i++){
    double rik=R(i,k);
    R(i,k)=R(i,k)*c-R(i,l)*s;
    R(i,l)=R(i,l)+R(i,k)*s;
  }
}
// Jacobi method eigensolver:
// - Runs jacobo_rotate until max off-diagonal element < eps
// - Writes the eigenvalues as entries in the vector "eigenvalues"
// - Writes the eigenvectors as columns in the matrix "eigenvectors"
// - Stops if it the number of iterations reaches "maxiter"
// - Writes the number of iterations to the integer "iterations"
// - Sets the bool reference "converged" to true if convergence was reached before hitting maxiter
void jacobi_eigensolver(arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations, bool& converged){
  int N=A.n_rows;
  arma::mat R=arma::mat(arma::size(A)).eye();
  int k;
  int l;
  double hinum=max_offdiag_symmetric(A, k, l);
  //std::cout<<"Came to while loop"<<std::endl;
  while (eps<abs(hinum) && iterations<maxiter){
    jacobi_rotate(A,R, k, l);
    hinum=max_offdiag_symmetric(A, k, l);
    iterations++;
  }
  for (int i=0; i<N; i++){
    eigenvalues(i)=A(i,i);
  }
  eigenvectors=R;
}
