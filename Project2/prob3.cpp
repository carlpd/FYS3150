#include <armadillo>
#include <iostream>
//#include <cstdlib>
#include <cmath>
#include <math.h>
using namespace arma;
int main(){
  int n=7;
  int N=(n-1);
  double h=1.0/n;
  mat A=mat(N,N).fill(0.);
  double a=-1.0/h;
  double d=2.0/h;
  vec lam=vec(N).fill(0.);
  mat v=mat(N,N).fill(0.);
  for (int i=0;i<=N-1; i++){
    std::cout<<i<<std::endl;
    lam(i)=d+2*a*cos((i+1)*M_PI/(N+1));
    for (int j=0;j<=N-1; j++){
      v(j,i)=sin((j+1)*(i+1)*M_PI*1.0/(1.0*N+1));
    }
  }
  A(0,0)=d;
  A(0,1)=a;
  for (int i=1;i<N-1; i++){
    A(i,i-1)=a;
    A(i,i)=d;
    A(i,i+1)=a;
  }
  A(N-1,N-2)=a;
  A(N-1,N-1)=d;
    std::cout<<"A"<<A<<std::endl;
  mat eigvec;
  vec eigval;
  eig_sym(eigval, eigvec, A);
  std::cout<<eigval<<"teoretiske"<<lam<<std::endl;
  std::cout<<normalise(eigvec)<<std::endl;
  std::cout<<normalise(v)<<std::endl;
  return 0;
}
