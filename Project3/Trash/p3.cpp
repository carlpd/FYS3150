#include "../hppfunc/p3.hpp"
#include <iostream>
/*
double V(arma::vec r){
  double V=
}*/
//Noen verdier for å gjøre tallene bedre
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;
//Finner det elektriske feltet
//arma::vec FindE(double V0, arma::vec r, double d){
arma::vec FindE(arma::vec r){
  arma::vec E=arma::vec(3).fill(0.);
  E(0)=V0*x/(d*d);
  E(1)=V0*y/(d*d);
  E(2)=2*V0*z/(d*d):
  return E;
}
//Finner kraften fra det elektriske feltet på partikkelen
/*
arma::vec EF(double V0, double d, Particle j){
  arma::vec E=FindE(V0, j.r, d);
  return q*E;
}*/
//Finner det magnetiske feltet i gitt i teksten
arma::vec FindB(double B0){
  arma::vec B=arma::vec(3).fill(0.);
  if (arma::norm(r, 2)>d){
    return B;
  }
  else{
    B(3)=B0;
    return B;
  }
}
//Finner den magnetiske kraften
/*
arma::vec BF(double B0, Particle j){
  double qp=j.q;
  arma::vec B=FindB(B0);
  arma::vec vp=j.v;
  arma::vec bf=q*arma::cross(B, v)
  return bf;
}*/
//Finner den totale kraften fra det eksterne feltet
//arma::vec EksF(double V0, double B0, double d, Particle j){
arma::vec EksF(Particle j){
  arma::vec ef=FindE(V0, j.r, d);
  double qp=j.q;
  arma::vec B=FindB(B0);
  arma::vec vp=j.v;
  arma::vec bf=arma::cross(B,v);
  arma::vec eksf=qp*(ef+bf);
  return eksf;
}
//Finner kraften mellom to partikler
arma::vec pij(Particle i, Particle j){
  fij=ke*j.q *(i.r-j.r)/std::powf(std::sqrtf(i.r(0)-j.r(0)+i.r(1)-j.r(1)+i.r(3)-j.r(3)), 3);
  return fij;
}
//Finner den totale kraften på partikkelen fra alle andre partikler
//arma::vec PF(Particle parts, int j){
arma::vec PF(int j){
  arma::vec pf=arma::vec(3).fill(0.);
  for i in range(i=0;i<parts.size(); i++){
    if (parts(i)!=parts(j)){
      pf=pf+fij(part(i), parts(j));
    }
  }
  return pf;
}
//Finner total kraft
//arma::vec TF(std::vec parts, int j, double B0, double V0, double d){
arma::vec TF(int j){
  Particle jp=parts(j);
  arma::vec eksf=EksF(V0, B0, d, jp);
  arma::vec intf=PF(parts, j);
  arma::vec totf=EksF+PF;
  return totf;
}
//Gjør om til neste tidsteg med Euler
void evolve_Euler(double dt){
  for (i=0;i<parts.size();i++){
    tfi=TF(i);
    parts(i).v=parts(i).v+dt*TF(i)/parts(i).m;
    parts(i).x=parts(i).x+dt*parts(i).v;
  }
}
