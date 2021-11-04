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
  delep+=s(a,b)*s(a-1,b);
  delep+=s(a,b)*s(a+1,b);
  delep+=s(a,b)*s(a,b+1);
  delep+=s(a,b)*s(a,b-1);
  delep=delep/N;
  return delep;
}
