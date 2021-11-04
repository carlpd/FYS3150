#inclde "../classes/ising2d.hpp"
arma::mat Ising2d::makerandomspins(){
  arma::mat S=arma::mat(L,L).randi(0,1);
  S=S*2 -1;
  return S;
}
arma::mat Ising2d::makeallupspins(int L){
  arma::mat S=arma::mat(L,L).fill(1);
  return S;
}

int Ising2d::findeps(int i, int j){
  int ep=0;
  int a=(i+L)%L;
  int b=(j+L)%L;
  ep+=s(i,j)*s(i-1,j);
  ep+=s(i,j)*s((i+1+L)%L,j);
  ep+=s(i,j)*s(i,(i+1+L)%L);
  ep+=s(i,j)*s(i,j-1);
  return ep;
}
