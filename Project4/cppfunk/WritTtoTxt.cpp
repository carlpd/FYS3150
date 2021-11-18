#include <fstream>
#include <armadillo>
#include <iostream>
#include <iomanip>
int main(){
  int TN=100;
  double Tstart=2.1;
  double Tend=2.4;
  int LN=4;
  int Lstart=40;
  int Lend=100;
  arma::vec T=arma::linspace(Tstart, Tend, TN);
  std::ofstream Ttxt ("../Txt/T.txt", std::ofstream::out);
  for (int i = 0; i<T.n_elem;i++){
    Ttxt << std::fixed;
    Ttxt << std::setprecision(6);
    Ttxt << T(i) << std::endl;
    std::cout << T(i) << std::endl;
  }
  Ttxt.close();
  return 0;
}
