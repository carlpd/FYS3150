#include <iostream>
#include <armadillo>

class Ising2d{
  double T;
  int L;
  int seed;
  Ising2d(double T, int L, int seed);
  arma_rng::set_seed(4832); //Endre til bedre random
};
