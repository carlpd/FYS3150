#include <armadillo>
using namespace arma;
int main(){
  int n=7;
  int N=(n-1);
  double h=1.0/n;
  mat A=mat(N,N).fill(0.);
  double a=-1.0/h;
  double d=2.0/h;
  for (int i=0;i<N-1; i++){
    A(i)=a;
    A(i+1)=d;
    A(i+2)=a;
  }
  A(N-2)=a;
  A(N-1)=d;
  mat eigvec;
  vec eigval;
  eig_sym(eigval, eigvec, A);
  std::cout<<eigval<<std::endl;
  return 0;
}
