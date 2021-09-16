#include "Project2H.hpp"

int main(){
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
