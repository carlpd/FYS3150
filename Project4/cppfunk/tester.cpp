arma_rng::set_seed(4832)
arma::mat makerandomspins(int L){
  arma::mat S=arma::mat(L,L).randi(0,1);
  S=S*2 -1;
  return S;
}
arma::mat makeallupspins(int L){
  arma::mat S=arma::mat(L,L).fill(1);
  return S;
}

finddeltaeps(int i, int j){
  s(i,j)
}
