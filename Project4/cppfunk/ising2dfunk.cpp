#include "../classes/ising2d.hpp"
#include <random>

double kb = 1;


Ising2d::Ising2d(double T_in, int L_in){
  T = T_in;
  L = L_in;
  N = L*L;
  double beta=1/T;
  bf(0)=std::exp(beta*(-8));
  bf(4)=std::exp(beta*(-4));
  bf(8)=std::exp(beta*(0));
  bf(12)=std::exp(beta*(4));
  bf(16)=std::exp(beta*(8));
}


arma::imat Ising2d::makerandomspins(){
  /*
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<int> RandomIntegerGenerator(0, 1);

  S=arma::mat(L,L);
  for (int i=0; i<L;i++){
    for (int j=0;j<L;j++){
      S(i,j)=RandomIntegerGenerator(gen);
    }
  }
  */
  //arma::mat S=arma::mat(L,L).randi(0,1);
  arma::arma_rng::set_seed(seed);
  arma::imat s = arma::randi<arma::imat>(L, L, arma::distr_param(0, 1));
  //std::cout<<s<<std::endl;
  S=s*2-1;
  //std::cout<<S<<std::endl;
  return S;
}
arma::imat Ising2d::makeallupspins(){
  arma::imat s=arma::imat(L,L).fill(1);
  S=s;
  return S;
}

void Ising2d::findeps(){
  ep=0;
  ep2 = 0;
  arma::imat s=S;
  S.print();
  for (int i=0; i<L; i++){
    for (int j=0; j<L; j++){

      //std::cout << i << " " << j << std::endl;

      //int iunder = (i-1+L)%L;
      int iover = (i+1+L)%L;
      //int junder = (j-1+L)%L;
      int jover = (j+1+L)%L;

      //std::cout << iover << " " << jover << std::endl;
      double dep = s(i,j)*s(iover,j);

      ep+=dep;
      //ep2+=dep*dep;

      dep = s(i,j)*s(i,jover);
      ep+=dep;
      /*
      dep=s(i,j)*s(i,junder);
      ep+=dep;
      ep2+=dep*dep;
      */
    }
  }
  ep=ep/N;
  ep2=ep*ep;
  epsrun=1;
}

void Ising2d::findmag(){
  M = 0;
  M2 = 0;
  for (int i=0; i<L; i++){
    for (int j=0; j<L; j++){
      int m = S(i, j);
      M = M + std::abs(m);
    }
  }
  M=M/N;
  M2=M*M;
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
//Finner en verdi den kan bruke for å finne eksponensialen
int Ising2d::FindDelE(int i, int j){

  int delsij=-2*S(i,j);
  int iunder = (i-1+L)%L;
  int iover = (i+1+L)%L;
  int junder = (j-1+L)%L;
  int jover = (j+1+L)%L;
  int sr=S(iover,j);
  sr+=S(iunder,j);
  sr+=S(i,jover);
  sr+=S(i,junder);
  int delE=delsij*sr;
  return delE;
}
//Finner et tilfeldig sted tilstanden
void Ising2d::findrandomspin(int &i, int &j){
  std::random_device rd;
  std::mt19937_64 gen(seed);
  std::uniform_int_distribution<int> RandomIntegerGenerator(0, L-1);
  i=RandomIntegerGenerator(gen);
  j=RandomIntegerGenerator(gen);
}
//Lag A, T, osv
//Lager T(x'->x_i)
//Mulig vi ikke trenger denne
double Ising2d::Rng(){
  std::mt19937_64 gen(seed);
  std::uniform_real_distribution<double> RandomProbGenerator(0, 1);
  double p =RandomProbGenerator(gen);
  return p;
}
// Lager A(xi->x')
double Ising2d::Ap(int i, int j){
  int dE=FindDelE(i, j);
  double p=bf(8+dE);
  if(p<1.){
    return p;
  }
  else if(p>1.){
    return 1.;
  }
}
//Test tilstanden
void Ising2d::makebreakstate(){
  int i;
  int j;
  findrandomspin(i, j);
  int dE=FindDelE(i, j);
  std::mt19937_64 gen(seed);
  std::uniform_real_distribution<double> RandomProbGenerator(0, 1);
  double p =RandomProbGenerator(gen);
  std::cout<<p<<std::endl;
  double AP=Ap(i, j);
  if(AP>p){
    S(i,j)=-S(i,j);
    ep+=dE/N;
    M+=2*S(i,j)/N;
    ep2=ep*ep;
    M2=M*M;
  }
  }

//Lag noen samples

//Lag A, T, osv