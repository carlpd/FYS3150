#include "../hppfunk/p3.hpp"
#include <iostream>
#include <cmath>
/*
double V(arma::vec r){
  double V=
}*/
//Noen verdier for å gjøre tallene bedre
/*
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7*/
//Finner det elektriske feltet
//arma::vec FindE(double V0, arma::vec r, double d){

Particle::Particle(double q_in, double m_in , arma::vec r_in, arma::vec v_in){
  q = q_in;
  m=m_in;
  r=r_in;
  v=v_in;
}

PenningTrap::PenningTrap(double B_in, double V_in, double f, double oV, double d_in, std::vector<class Particle> parts_in){
  B0=B_in;
  V0=V_in;
  pf=f;
  poV = oV;
  d=d_in;
  parts=parts_in;
}

void PenningTrap::add_particle(Particle vals){
  parts.push_back(vals);
}

void PenningTrap::add_randomparticle(){
  double rq=1.0;
  double rm=1.0;
  arma::vec rr=arma::vec(3).randu();
  rr=rr-arma::vec(3).fill(0.5);
  rr=rr*d*2;
  arma::vec rv=arma::vec(3).randu();
  rv=rv-arma::vec(3).fill(0.5);
  rv=rv*d;
  Particle vals(rq, rm, rr, rv);
  parts.push_back(vals);
}
//Finner kraften fra det elektriske feltet på partikkelen
arma::vec PenningTrap::FindEVt(arma::vec r, double t){
  arma::vec E=arma::vec(3).fill(0.);
  double x=r(0);
  double y=r(1);
  double z=r(2);
  E(0)=V0*(1+pf*std::cos(poV*t))*x/(d*d);
  E(1)=V0*(1+pf*std::cos(poV*t))*y/(d*d);
  E(2)=-2*V0*(1+pf*std::cos(poV*t))*z/(d*d);
  return E;
}




//Finner det magnetiske feltet i gitt i teksten
arma::vec PenningTrap::FindB(double B0){
  arma::vec B=arma::vec(3).fill(0.);
  B(2)=B0;
  return B;
}


//Finner den totale kraften fra det eksterne feltet
//arma::vec EksF(double V0, double B0, double d, Particle j){
arma::vec PenningTrap::EksF(Particle j, double t){
  arma::vec ef=FindEVt(j.r, t);
  double qp=j.q;
  arma::vec B=FindB(B0);
  arma::vec vp=j.v;
  arma::vec bf=arma::cross(vp,B);
  arma::vec eksf=qp*(ef+bf);
  //std::cout<<B<<std::endl;
  //std::cout<<"E"<<ef<<std::endl;
  //exit(0);
  return eksf;
}

//Finner kraften mellom to partikler
arma::vec PenningTrap::pij(Particle i, Particle j){
  double dist=arma::norm(i.r-j.r);
  std::cout<<dist<<std::endl;
  //arma::vec fij=ke*j.q *(i.r-j.r)/std::pow(std::sqrt(i.r(0)-j.r(0)+i.r(1)-j.r(1)+i.r(2)-j.r(2)), 3);
  arma::vec fij=ke*j.q *(i.r-j.r)/std::pow(dist, 3);
  return fij;
}

//Finner den totale kraften på partikkelen fra alle andre partikler
//arma::vec PF(Particle parts, int j){

arma::vec PenningTrap::PF(int j){
  arma::vec pf=arma::vec(3).fill(0.);
  for (int i=0;i<parts.size(); i++){
    //if (parts[i].r(0)!=parts[j].r(0)&&parts[i].r(1)!=parts[j].r(1)&&parts[i].r(2)!=parts[j].r(2)){
    if (i!=j){
      pf=pf+pij(parts[i], parts[j]);
    }
  }
  //std::cout<<"PF"<<pf<<std::endl;
  return pf;
}

//Finner total kraft
//arma::vec TF(std::vec parts, int j, double B0, double V0, double d){
arma::vec PenningTrap::TF(int j, double t){
  if(parts.size()==1 || partint==false){
    Particle jp=parts[j];
    //std::cout<<"Her3"<<std::endl;
    arma::vec eksf=EksF(jp, t);
    arma::vec totf=eksf;//+intf;
    //std::cout<<"TF"<<totf<<std::endl;
    return totf;
  }
  else{
    Particle jp=parts[j];
    //std::cout<<"Her3"<<std::endl;
    arma::vec eksf=EksF(jp, t);
    //std::cout<<"Her4"<<std::endl;
    arma::vec intf=PF(j);
    arma::vec totf=eksf+intf;
    //std::cout<<"TF"<<totf<<std::endl;
    return totf;
  }
}

//Gjør om til neste tidsteg med Euler
void PenningTrap::evolve_Euler(double dt, double t){
  //std::cout<<"rstart"<<parts[0].r <<std::endl;
  for (int i=0;i<parts.size();i++){
    //std::cout<<"Her"<<std::endl;
    arma::vec tfi=TF(i, t);
    //std::cout<<"tfi"<<tfi<<std::endl;
    //std::cout<<"Her2"<<std::endl;
    parts[i].v=parts[i].v+tfi*dt/parts[i].m;
    parts[i].r=parts[i].r+parts[i].v*dt;
    //std::cout<<parts[i].r<<std::endl;
    //std::cout<<parts[i].v*dt<<std::endl;
    //arma::vec a=parts[i].r+parts[i].v*dt;
    //std::cout<<parts[i].r<<std::endl;
    //std::cout<<i<<std::endl;
  }
}
void PenningTrap::evolve_RK4(double dt, double t){
  /*
  std::vector<arma::vec> Fo;
  for (int i=0; i<parts.size();i++){
    Fo.push_back(TF(i));
  }*/
  for (int i=0; i<parts.size();i++){
    arma::vec rold=parts[i].r ;
    arma::vec vold=parts[i].v;
    arma::vec vk1=dt*TF(i, t)/parts[i].m;
    arma::vec rk1=dt*parts[i].v ;
    parts[i].v=vold+vk1/2.0;
    parts[i].r=rold+rk1/2.0;
    arma::vec vk2=dt* TF(i, t)/parts[i].m;
    arma::vec rk2=dt*parts[i].v;
    parts[i].v=vold+vk2/2.0;
    parts[i].r=rold+rk2/2.0;
    arma::vec vk3=dt* TF(i, t)/parts[i].m;
    arma::vec rk3=dt*parts[i].v;
    parts[i].v=vold+vk3;
    parts[i].r=rold+rk3;
    arma::vec vk4=dt* TF(i, t)/parts[i].m;
    arma::vec rk4=dt*parts[i].v;
    parts[i].v=vold+(vk1+2*vk2+2*vk3+vk4)/6;
    parts[i].r=rold+(rk1+2*rk2+2*rk3+rk4)/6;
  }
}
