#include "../hppfunk/p3.hpp"
#include "../hppfunk/finderrors.hpp"
#include <fstream>
int main(){
  arma::vec pr1=arma::vec(3).fill(0.);
  arma::vec pv1=arma::vec(3).fill(0.);
  pr1={1.0, 0.0, 1.0};
  pv1={0.0, 1.0, 0.0};
  double q1=1.0;
  double m1=20.0;
  Particle p{q1,m1,pr1,pv1};
  double dt=0.0001;
  makeRK4txt(p, dt);
  return 0;
}
