#include "../classes/ising2d.hpp"
#include <random>
#include <sstream>
#include <string>
double kb = 1;



Ising2d::Ising2d(double T_in, int L_in){
  T_ = T_in;
  L_ = L_in;
  N_ = L_*L_;
  Ninv_ = 1./N_;
  double beta=1./T_;
  bf_(0)=std::exp(beta*(8));
  bf_(4)=std::exp(beta*(4));
  bf_(8)=std::exp(beta*(0));
  bf_(12)=std::exp(beta*(-4));
  bf_(16)=std::exp(beta*(-8));
}


arma::imat Ising2d::makerandomspins(double factor = 1.){
  arma::arma_rng::set_seed(seed_*factor);
  arma::imat s = arma::randi<arma::imat>(L_, L_, arma::distr_param(0, 1));
  S_=s*2-1;
  return S_;
}
arma::imat Ising2d::makeallupspins(){
  arma::imat s=arma::imat(L_,L_).fill(1);
  S_=s;
  return S_;
}

void Ising2d::findeps(){
  ep_=0;
  ep2_ = 0;
  arma::imat s=S_;
  //S_.print();
  for (int i=0; i<L_; i++){
    for (int j=0; j<L_; j++){

      //std::cout << i << " " << j << std::endl;

      //int iunder = (i-1+L)%L;
      int iover = (i+1+L_)%L_;
      //int junder = (j-1+L)%L;
      int jover = (j+1+L_)%L_;

      //std::cout << iover << " " << jover << std::endl;
      double dep = s(i,j)*s(iover,j);

      ep_-=dep;
      ep2_ = dep*dep;
      //ep2+=dep*dep;

      dep = s(i,j)*s(i,jover);
      ep_-=dep;
      ep2_= dep*dep;
    }
  }
  std::cout<<ep_<<std::endl;
  epsrun_=1;
}

void Ising2d::findmag(){
  M_ = 0;
  M2_ = 0;
  for (int i=0; i<L_; i++){
    for (int j=0; j<L_; j++){
      int m = S_(i, j);
      M_ = M_ + m;
    }
  }
  M_=M_;
  M2_=M_*M_;
  magrun_=1;
}

void Ising2d::findCv(){
  if (epsrun_==0){
    findeps();
  }
  if (magrun_==0){
    findmag();
  }
  Cv_ = 1/(kb*T_*T_)*(ep2_/N_ - ep_*ep_/N_);
  CvRun_ = 1;
}

void Ising2d::findX(){
  if (epsrun_==0){
    findeps();
  }
  if (magrun_==0){
    findmag();
  }
  X_ = 1/(kb*T_)*(M2_/N_ - M_*M_/N_);
  Xrun_ = 1;
}

void Ising2d::findall(){
  if (CvRun_==0){
    findCv();
  }
  if (Xrun_==0){
    findX();
  }
}
//Finner en verdi den kan bruke for å finne eksponensialen
int Ising2d::FindDelE(int i, int j){

  int delsij=2*S_(i,j);
  int iunder = (i-1+L_)%L_;
  int iover = (i+1+L_)%L_;
  int junder = (j-1+L_)%L_;
  int jover = (j+1+L_)%L_;
  int sr=S_(iover,j);
  sr+=S_(iunder,j);
  sr+=S_(i,jover);
  sr+=S_(i,junder);
  int delE=delsij*sr;
  return delE;
}
//Finner et tilfeldig sted tilstanden
void Ising2d::findrandomspin(int &i, int &j){
  i=arma::randi<int>(arma::distr_param(0, L_-1));
  j=arma::randi<int>(arma::distr_param(0, L_-1));
}
//Lag A, T, osv
//Lager T(x'->x_i)
//Mulig vi ikke trenger denne
double Ising2d::Rng(){
  double p =arma::randu<double>();
  return p;
}
// Lager A(xi->x')
double Ising2d::Ap(int dE){
  //int dE=FindDelE(i, j);
  double p=bf_(8+dE);
  return p;
}
//Test tilstanden
void Ising2d::makebreakstate(){
  int i;
  int j;
  findrandomspin(i, j);
  int dE=FindDelE(i, j);
  if(dE<0){
    S_(i,j)*=-1;
    ep_+=dE;
    M_+=2*S_(i,j);
    ep2_+=dE*dE;
    M2_=M_*M_;
    //std::cout<<"Changed"<<std::endl;
  }

  else if(Ap(dE)>arma::randu()){
    S_(i,j)*=-1;
    ep_+=dE;
    //std::cout<<ep_<<std::endl;
    M_+=2*S_(i,j);
    ep2_+=dE*dE;
    M2_=M_*M_;
    //std::cout<<"Changed"<<std::endl;
  }
}

//Lag noen samples

//Lag A, T, osv
