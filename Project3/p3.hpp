#include <armadillo>
#include <iostream>

class Particle{
  public:
    double q; //Charge
    double m; //Mass
    arma::vec r; //position
    arma::vec v; //Velocity
};
class PenningTrap
{
  public:
    double B0;
    double V0;
    double d;
    std::vector<class Particle> parts;
    void add_particle(Particle vals);
    arma::vec EksF(Particle j);
    arma::vec pij(Particle i, Particle j);
    arma::vec PF(int j);
    arma::vec TF(int j);
    void evolve_Euler(double dt);
};
/*
arma::vec EksF(double V0, double B0, double d, Particle j);
arma::vec pij(Particle i, Particle j);
arma::vec PF(Particle parts, int j);
arma::vec TF(std::vec parts, int j, double B0, double V0, double d);
*/
