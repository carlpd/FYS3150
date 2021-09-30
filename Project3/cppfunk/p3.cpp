#include "../hppfunc/p3.hpp"
#include <iostream>
/*
double V(arma::vec r){
  double V=
}*/
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;
arma::vec FindE(double V0, arma::vec, double d){
  arma::vec E=arma::vec(3).fill(0.);
  E(0)=V0*x/(d*d);
  E(1)=V0*y/(d*d);
  E(2)=2*V0*z/(d*d):
  return E;
}
arma::vec FindB(dobule B0){
  arma::vec B=arma::vec(3).fill(0.);
  B(3)=B0;
  retrn B;
}
arma::vec pij(Particle i, Particle j){
  fij=ke*j.q *(i.r-j.r)/std::powf(std::sqrtf(i.r(0)-j.r(0)+i.r(1)-j.r(1)+i.r(3)-j.r(3)), 3);
  return fij;
}
arma::vec PF(Particle parts, int j){
  arma::vec pf=arma::vec(3).fill(0.);
  for i in range(i=0;i<parts.size(); i++){
    if (parts(i)!=parts(j)){
      pf=pf+fij(part(i), parts(j));
    }
  }
  return pf;
}
