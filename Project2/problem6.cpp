#include "Project2.hpp"
#include <fstream>
using namespace arma;
int main(){
  std::ofstream fs;
  fs.open("Data/Iterations.txt");
  std::streambuf* orig_buf = cout.rdbuf();
  std::cout.rdbuf(NULL);
  for (int n = 7; n < 100; n++){
    int N=(n-1);
    double h=1.0/n;
    std::cout<<h<<std::endl;
    mat A=mat(N,N).fill(0.);
    double a=-1.0/(h*h);
    std::cout<<a<<std::endl;
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
    A.print();
    vec eigenvalues=arma::vec(N).fill(0.);
    mat eigenvectors;
    int iterations=0;
    bool converged=false;
    int maxiter=std::pow(10, 6);
    double eps=1e-11;
    jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);
    std::cout.rdbuf(orig_buf);
    std::cout<<"n = "<<n<< " Iterations = "<<iterations<<std::endl;
    fs<<"n = "<<n<< " Iterations = "<<iterations<<std::endl;
    std::cout.rdbuf(NULL);
  }
  fs.close();
  return 0;
}
