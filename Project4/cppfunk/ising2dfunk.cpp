arma_rng::set_seed(4832) //Endre til bedre random
arma::mat makerandomspins(int L){
  arma::mat S=arma::mat(L,L).randi(0,1);
  S=S*2 -1;
  return S;
}
arma::mat makeallupspins(int L){
  arma::mat S=arma::mat(L,L).fill(1);
  return S;
}

int finddeltaeps(int i, int j){
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
