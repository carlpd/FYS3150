#include "../classes/ising2d.hpp"
#include <random>

double kb = 1;


Ising2d::Ising2d(double T_in, int L_in){
  T = T_in;
  L = L_in;
  N = L*L;
}


arma::mat Ising2d::makerandomspins(){
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<int> RandomIntegerGenerator(0, 1);
  S=arma::mat(L,L);
  for (int i=0; i<L;i++){
    for (int j=0;j<L;j++){
      S(i,j)=RandomIntegerGenerator(gen);
    }
  }
  S=S*2-1;
  return S;
}
arma::mat Ising2d::makeallupspins(int L){
  arma::mat S=arma::mat(L,L).fill(1);
  return S;
}

void Ising2d::findeps(){
  ep=0;
  ep2 = 0;
  arma::mat s=S;
  S.print();
  for (int i=0; i<L; i++){
    for (int j=0; j<L; j++){

      std::cout << i << " " << j << std::endl;

      int iunder = (i-1+L)%L;
      int iover = (i-1+L)%L;
      int junder = (j-1+L)%L;
      int jover = (j-1+L)%L;

      std::cout << iunder << " " << iover << " " << junder << " " << jover << std::endl;
      double dep = s(i,j)*s(iunder,j);

      ep+=dep;
      ep2+=dep*dep;

      dep = s(i,j)*s(iover,j);
      ep+=dep;
      ep2+=dep*dep;

      dep=s(i,j)*s(i,jover);
      ep+=dep;
      ep2+=dep*dep;

      dep=s(i,j)*s(i,junder);
      ep+=dep;
      ep2+=dep*dep;
    }
  }
  epsrun=1;
}

void Ising2d::findmag(){
  M = 0;
  M2 = 0;
  for (int i=0; i<L; i++){
    for (int j=0; j<L; j++){
      int m = S(i, j);
      M = M + std::abs(m);
      M2 = M2 + m*m;
    }
  }
  magrun=1;
}

void Ising2d::findCv(){
  if (epsrun==0){
    findeps();
  }
  if (magrun==0){
    findmag();
  }
  Cv = 1/(kb*T*T)*(ep2/N - ep*ep/N);
  CvRun = 1;
}

void Ising2d::findX(){
  if (epsrun==0){
    findeps();
  }
  if (magrun==0){
    findmag();
  }
  X = 1/(kb*T)*(M2/N - M*M/N);
  Xrun = 1;
}

void Ising2d::findall(){
  if (CvRun==0){
    findCv();
  }
  if (Xrun==0){
    findX();
  }
}
