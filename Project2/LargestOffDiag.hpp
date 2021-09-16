#include <iostream>
#include <armadillo>


double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){
  int rows = A.n_rows;
  int cols = A.n_cols;
  double current_highest = 0.;
  //Tester kun for den øvre delen av diagonalen siden A er symmetrisk
  //Vil si at i går gjennom alle kolonner
  //Og at j går fra den kolonnens diagonalelement og utover
  for (int i = 0; i < rows; i++){
    for (int j = i+1; j < cols; j++){
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
