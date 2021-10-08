#include "../hppfunk/p3.hpp"
#include <iostream>
#include <cmath>
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

Particle::Particle(double q_in, double m_in , arma::vec r_in, arma::vec v_in){
  q = q_in;
  m=m_in;
  r=r_in;
  v=v_in;
}

PenningTrap::PenningTrap(double B_in, double V_in, double d_in, std::vector<class Particle> parts_in){
  B0=B_in;
  V0=V_in;
  d=d_in;
  parts=parts_in;
}

void PenningTrap::add_particle(Particle vals){
  parts.push_back(vals);
}

void PenningTrap::add_randomparticle(){
  double rq=ke;
  double rm=1;
  arma::vec rr=arma::vec(3).randu();
  rr=rr-arma::vec(3).fill(0.5);
  rr=rr*d;
  arma::vec rv=arma::vec(3).randu();
  rv=rv-arma::vec(3).fill(0.5);
  rv=rv*2;
  Particle vals(rq, rm, rr, rv);
  parts.push_back(vals);
}
//Finner kraften fra det elektriske feltet på partikkelen
arma::vec PenningTrap::FindE(arma::vec r){
  arma::vec E=arma::vec(3).fill(0.);
  double x=r(1);
  double y=r(2);
  double z=r(3);
  E(0)=V0*x/(d*d);
  E(1)=V0*y/(d*d);
  E(2)=2*V0*z/(d*d);
  return E;
}




//Finner det magnetiske feltet i gitt i teksten
arma::vec PenningTrap::FindB(double B0){
  arma::vec B=arma::vec(3).fill(0.);
  B(3)=B0;
  return B;
}


//Finner den totale kraften fra det eksterne feltet
//arma::vec EksF(double V0, double B0, double d, Particle j){
arma::vec PenningTrap::EksF(Particle j){
  arma::vec ef=FindE(j.r);
  double qp=j.q;
  arma::vec B=FindB(B0);
  arma::vec vp=j.v;
  arma::vec bf=arma::cross(B,vp);
  arma::vec eksf=qp*(ef+bf);
  return eksf;
}

//Finner kraften mellom to partikler
arma::vec PenningTrap::pij(Particle i, Particle j){
  arma::vec fij=ke*j.q *(i.r-j.r)/std::pow(std::sqrt(i.r(0)-j.r(0)+i.r(1)-j.r(1)+i.r(3)-j.r(3)), 3);
  return fij;
}

//Finner den totale kraften på partikkelen fra alle andre partikler
//arma::vec PF(Particle parts, int j){

arma::vec PenningTrap::PF(int j){
  arma::vec pf=arma::vec(3).fill(0.);
  for (int i=0;i<parts.size(); i++){
    if (parts[i].r(0)!=parts[j].r(0)&&parts[i].r(1)!=parts[j].r(1)&&parts[i].r(2)!=parts[j].r(2)){
      pf=pf+pij(parts[i], parts[j]);
    }
  }
  return pf;
}

//Finner total kraft
//arma::vec TF(std::vec parts, int j, double B0, double V0, double d){
arma::vec PenningTrap::TF(int j){
  Particle jp=parts[j];
  arma::vec eksf=EksF(jp);
  arma::vec intf=PF(j);
  arma::vec totf=eksf+intf;
  return totf;
}

//Gjør om til neste tidsteg med Euler
void PenningTrap::evolve_Euler(double dt){
  for (int i=0;i<parts.size();i++){
    arma::vec tfi=TF(i);
    parts[i].v=parts[i].v+dt*TF(i)/parts[i].m;
    parts[i].r=parts[i].r+dt*parts[i].v;
  }
}
