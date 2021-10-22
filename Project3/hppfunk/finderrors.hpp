#include <armadillo>
#include <iostream>
#include <cmath>
double abserr(arma::vec an, arma::vec num);
double relerr(arma::vec an, arma::vec num);
arma::vec analytical(double t, Particle p1);
void makeRK4txt(Particle p1, double dt);
void makeEulertxt(Particle p1, double dt);
