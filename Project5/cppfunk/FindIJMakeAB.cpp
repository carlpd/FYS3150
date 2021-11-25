#inlcude <iostream>
#include <armadillo>

// u_1,1 , u_2,1 , u_1,2, u_2,2
// Teller gjennom antall i i en rad, gir k = i + j*(M-2)

int FindK(int i, int j, int M){
  int k =  i + j*(M-2);
  return k;
}

void MakeAB(arma::mat& A, arma::mat& B, vec a, vec b, double r){
  for (int i = 0; i<9;i++){
    A(i, i) = a(i); B(i,i) = b(i);
  }
  for (int i = 0; i<8;i++){
    A(i, i+1) = -r; B(i, i+1) = r;
    A(i+1, i) = -r; B(i+1, i) = r;
  }

  A(3, 2) = 0; B(3, 2) = 0;
  A(2, 3) = 0; B(2, 3) = 0;
  A(5, 6) = 0; B(5, 6) = 0;
  A(6, 5) = 0; B(6, 5) = 0;

  for (int i = 0; i<6; i++){
    A(i+3, i) = -r; B(i+3, i) = r;
    A(i, i+3) = -r; B(i, i+3) = r;
  }
}
