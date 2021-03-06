#include "Project2.hpp"
using namespace arma;
int main(){
  // n=10; //For a
  int n=101;
  int N=(n-1);
  double h=1.0/n;
  //std::cout<<h<<std::endl;
  mat A=mat(N,N).fill(0.);
  double a=-1.0/(h*h);
  //std::cout<<a<<std::endl;
  double d=2.0/(h*h);
  A(0,0)=d;
  A(0,1)=a;
  for (int i=1;i<N-1; i++){
    A(i,i-1)=a;
    A(i,i)=d;
    A(i,i+1)=a;
  }
  A(N-1,N-2)=a;
  A(N-1,N-1)=d;
  //A.print();
  vec eigenvalues=arma::vec(N).fill(0.);
  mat eigenvectors;
  int iterations=0;
  bool converged=false;
  int maxiter=std::pow(10, 6);
  double eps=1e-11;
  //eig_sym(eigenvalues, eigenvectors, A);
  /*int k;
  int l;
  double hinum=max_offdiag_symmetric(A, k, l);
  mat R=mat(size(A)).eye();
  jacobi_rotate(A, R, k, l);*/
  jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);
  //std::cout<<A<<std::endl;
  //std::cout<<"eigenvalues"<<eigenvalues<<std::endl;
  //std::cout<<"eigenvectors"<<std::endl;
  //std::cout<<eigenvectors<<std::endl;
  std::cout<<converged<<std::endl;
  arma::mat low3=findthreelowestvals(eigenvalues,eigenvectors);
  std::ofstream fs;
  // fs.open("Data/eigenvecs7n100.txt"); //For a
  fs.open("Data/eigenvecs7n100.txt");
  for (int i=0;i<low3.n_rows;i++){
    fs<<low3(i,0)<<" "<<low3(i,1)<<" "<<low3(i,2)<<std::endl;
  }
  return 0;
}
