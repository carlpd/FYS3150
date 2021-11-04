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

int Ising2d::finddeltaeps(int i, int j){
  int delep=0;
  int a=(i+L)%L;
  int b=(j+L)%L;
  delep+=s(i,j)*s(i-1,j);
  delep+=s(i,j)*s((i+1+L)%L,j);
  delep+=s(i,j)*s(i,(i+1+L)%L);
  delep+=s(i,j)*s(i,j-1);
  delep=delep/N;
  return delep;
}

int Ising2d::findtotalmag(s){
  M = 0
  for (int i=0; i<L, i++){
    for (int j=0; j<L, i++){
      M = M + s(i, j);
    }
  }
  return M;
}
