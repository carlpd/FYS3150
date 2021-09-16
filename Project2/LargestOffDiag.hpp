#include <iostream>
#include <armadillo>
#include <cmath>

double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){
  int rows = A.n_rows;
  int cols = A.n_cols;
  double current_highest = 0;
  //Tester kun for den øvre delen av diagonalen siden A er symmetrisk
  //Vil si at i går gjennom alle kolonner
  //Og at j går fra den kolonnens diagonalelement og utover
  std::cout << A;
  for (int i = 0; i < rows; i++){
    for (int j = i+1; j < cols; j++){
      //Matrisene henter element row-col så blir omvendt av for-løkkene
      double element = cmath::abs(A(i,j));
      std::cout << i << j << std::endl;
      if (element > current_highest){
        current_highest = A(i, j);
        //Setter rad-nummeret til k og kolonnenummeret til l
        int& k = i;
        int& l = j;
      }
    }
  }
  std::cout << current_highest << " " << k << " "<< l;
  return current_highest;
}
