#include "Project2.hpp"

int main(){
  /*if (A.is_square() == false){
    throw std::invalid_argument("A not a square matrix");
  }
  int rows = A.n_rows;
  if (rows < 2){
    throw std::invalid_argument("A must be larger than 1x1");
  }*/
  arma::mat A(4,4, arma::fill::zeros);
  arma::vec c = {0.5, -0.7, -0.7, 0.5};
  int rows = A.n_rows;
  for (int i=0; i<rows; i++){
    A(i, i) = 1;
    A(rows-i -1, i) = c(i);
  }
  int k = 0;
  int l = 0;
  double MaxAbs = max_offdiag_symmetric(A, k, l);
  std::cout << MaxAbs << ", k = " << k << ", l = "<< l << std::endl;
}
