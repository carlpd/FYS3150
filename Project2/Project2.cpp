#include "Project2.hpp"
using namespace arma;
int main(){
  int n=7;
  int N=(n-1);
  double h=1.0/n;
  mat A=mat(N,N).fill(0.);
  double a=-1.0/h;
  double d=2.0/h;
  A(0,0)=d;
  A(0,1)=a;
  for (int i=1;i<N-1; i++){
    A(i,i-1)=a;
    A(i,i)=d;
    A(i,i+1)=a;
  }
  A(N-1,N-2)=a;
  A(N-1,N-1)=d;
  vec eigenvalues=arma::vec(N).fill(0.);
  mat eigenvectors;
  int iterations=0;
  bool converged=false;
  int maxiter=std::pow(10, 6);
  double eps=1e-8;
  /*int k;
  int l;
  double hinum=max_offdiag_symmetric(A, k, l);
  mat R=mat(size(A)).eye();
  jacobi_rotate(A, R, k, l);*/
  jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);
  std::cout<<A<<std::endl;
  std::cout<<eigenvalues<<std::endl;
  std::cout<<normalise(eigenvectors)<<std::endl;
  vec lam=vec(N).fill(0.);
  mat v=mat(N,N).fill(0.);
  for (int i=0;i<=N-1; i++){
    //std::cout<<i<<std::endl;
    lam(i)=d+2*a*cos((i+1)*M_PI/(N+1));
    for (int j=0;j<=N-1; j++){
      v(j,i)=sin((j+1)*(i+1)*M_PI*1.0/(1.0*N+1));
    }
  }
  std::cout<<normalise(v)<<std::endl;
  std::cout<<converged<<std::endl;
  return 0;
}
