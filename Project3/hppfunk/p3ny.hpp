#include <armadillo>
#include <iostream>
#include <cmath>
class Particle{
  public:
    double q; //Charge
    double m; //Mass
    arma::vec r; //position
    arma::vec v; //Velocity
    Particle(double q_in, double m_in , arma::vec r_in, arma::vec v_in);
};
class PenningTrap
{
  public:
    double pf;
    double poV;
    double ke=1.38935333e5;
    double Tesla=9.64852558e1;
    double Volt=9.64852558e7;
    double B0;
    double V0;
    double d;
    std::vector<class Particle> parts;
    PenningTrap(double B_in, double V_in, double f, double oV, double d_in, std::vector<class Particle> parts_in);
    bool partint=false;
    void add_particle(Particle vals);
    void add_randomparticle();
    arma::vec FindEVt(arma::vec r, double t);
    arma::vec FindB(double B0);
    arma::vec EksF(Particle j, double t);
    arma::vec pij(Particle i, Particle j);
    arma::vec PF(int j);
    arma::vec TF(int j, double t);
    void evolve_Euler(double dt, double t);
    void evolve_RK4(double dt, double t);
    int KeptInside();
};
/*
arma::vec EksF(double V0, double B0, double d, Particle j);
arma::vec pij(Particle i, Particle j);
arma::vec PF(Particle parts, int j);
arma::vec TF(std::vec parts, int j, double B0, double V0, double d);
*/
