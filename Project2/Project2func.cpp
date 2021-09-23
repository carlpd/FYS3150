#include "Project2.hpp"

double max_offdiag_symmetric(arma::mat& A, int& k, int& l){
  if (A.is_square() == false){
    throw std::invalid_argument("A not a square matrix");
  }
  int rows = A.n_rows;
  if (rows < 2){
    throw std::invalid_argument("A must be larger than 1x1");
  }
  double current_highest = 0.0;
  //Tester kun for den øvre delen av diagonalen siden A er symmetrisk
  //Vil si at i går gjennom alle kolonner
  //Og at j går fra den kolonnens diagonalelement og utover
  for (int i = 0; i < rows; i++){
    for (int j = i+1; j < rows; j++){
      //Matrisene henter element row-col så blir omvendt av for-løkkene
      double element = std::fabs(A(i,j));
      //if ((element > std::fabs(current_highest))==1){
      if (element > current_highest){
        current_highest = element;
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
  //double tm = -tau- std::sqrt(1+std::pow(tau, 2));
  //double tp = -tau + std::sqrt(1+std::pow(tau,2));
  double t;
  double c;
  double s;
  if (A(k,l)!=0.0){
    if (tau>0.0){
      t=1.0/(tau+sqrt(tau*tau+1.0));
    }
    else{
      t=(-1.0)/(-tau+sqrt(tau*tau+1.0));
    }
    c=1.0/sqrt(1.0+t*t);
    s=c*t;
  }
  else{
    t=0.0;
    s=0.0;
    c=1.0;
  }
  double akk;
  double all;
  double aik;
  double ail;
  double rik;
  double ril;
  akk=A(k,k);
  all=A(l,l);
  //std::cout<<"Starting transform"<<std::endl;
  //Tranformerer A(m) til A(m+1)
  A(k,k)=akk*c*c-2.*A(k,l)*c*s+all*s*s;
  A(l,l)=all*c*c+2.*A(k,l)*c*s+akk*s*s;
  A(k,l)=0.0;
  A(l,k)=0.0;
  for(int i=0;i<A.n_rows;i++){
    if (i!=l && i!=k){
      aik=A(i,k); //lagrer for to linjer under
      ail=A(i,l);
      A(i,k)=aik*c-ail*s;
      A(k,i)=A(i,k);
      A(i,l)=ail*c+aik*s;
      A(l,i)=A(i,l);
    }
  }
  //std::cout<<"Went thorugh transform"<<std::endl;
  //Oppdaterer R
  for(int i=0; i<A.n_rows; i++){
    rik=R(i,k);
    ril=R(i,l);
    R(i,k)=rik*c-ril*s;
    R(i,l)=c*ril+rik*s;
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
  while (eps<hinum && iterations<maxiter){
    jacobi_rotate(A,R, k, l);
    hinum=max_offdiag_symmetric(A, k, l);
    iterations++;
    std::cout<<hinum<<std::endl;
  }
  std::cout<<hinum<<std::endl;
  if (eps>hinum){
    converged=true;
  }
  for (int i=0; i<N; i++){
    eigenvalues(i)=A(i,i);
  }
  eigenvectors=R;
}
//Problem 7
arma::mat findthreelowestvals(arma::vec eigenvalues, arma::mat eigenvectors){
  double a=1e20;
  int ai;
  double b=1e20;
  int bi;
  double c=1e20;
  int ci;
  for (int i=0;i<eigenvalues.n_elem;i++){
    if (eigenvalues(i)>1e20){
      throw std::invalid_argument("Eignevalue has to be lower!");
    }
    if(a>eigenvalues(i)){
      a=eigenvalues(i);
      ai=i;
    }
  }
  for (int i=0;i<eigenvalues.n_elem;i++){
    if (b>eigenvalues(i)&&i!=ai){
      b=eigenvalues(i);
      bi=i;
    }
  }
  for (int i=0;i<eigenvalues.n_elem;i++){
    if (c>eigenvalues(i)&&i!=ai&&i!=bi){
      c=eigenvalues(i);
      ci=i;
    }
  }
  arma::mat o=arma::mat(eigenvectors.n_cols, 3).fill(0.);
  o.col(0)=eigenvectors.col(ai);
  o.col(1)=eigenvectors.col(bi);
  o.col(2)=eigenvectors.col(ci);
  return o;
}
