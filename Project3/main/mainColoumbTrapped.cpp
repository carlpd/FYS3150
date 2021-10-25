#include "../hppfunk/p3ny.hpp"
#include <fstream>
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;

int main(){
  double tV0=0.0025*Volt;
  double tB0=1.0*Tesla;
  double td=1e4/20;
  double q1=1.0;
  double m1=20.0;
  arma::vec vf = arma::vec(3).fill(0.);
  vf={0.4};
  double dOv = 0.02;
  int NoV = 35;
  arma::vec vOv = arma::linspace(0.5, 0.9, NoV);
  double tmax=500;
  double dt=0.01;
  int N=(int)(tmax/dt);
  arma::vec t=arma::linspace(0, tmax, N );
  std::ofstream Inside;
  std::string file = "Out10/TrappedZoomed.txt";
  Inside.open(file);

  for (auto f : vf){
    for (auto oV : vOv){
      std::cout<<f<<" "<<oV<<std::endl;
      //Initialiserer PenningTrap
      std::vector<class Particle> tparts;
      PenningTrap Trap=PenningTrap(tB0, tV0, f, oV, td, tparts);
      //Coloumb interaksjoner
      Trap.partint = false;
      //Fyller penning trap med tilfeldioge partikler
      int RanParticles = 100;
      for (int i=0; i<RanParticles; i++){
        Trap.add_randomparticle();
      }
      for(int i=0; i<N; i++){
        Trap.evolve_RK4(dt, t(i));
        }
      int Trapped = Trap.KeptInside();
      Inside<<f<<" "<<oV<<" "<<Trapped<< std::endl;
      }
    }

  Inside.close();
  return 0;
}
