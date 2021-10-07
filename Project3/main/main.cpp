#include "../hppfunk/p3.hpp"
#include <fstream>
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;

int main(){

  //Particle first_particle(q,m,r,v);
  //PenningTrap.add_particle(first_particle);
  double tV0=10.0*Volt;
  double tB0=1.0*Tesla;
  double td=1e4;
  std::vector<class Particle> tparts;
  PenningTrap test=PenningTrap(tV0, tB0, td, tparts);
  test.add_randomparticle();
  test.add_randomparticle();
  int N=1000;
  arma::vec t=arma::linspace(0, 10, N);
  double dt=10/(N+1);
  std::ofstream(text);
  text.open("../Txtfiler/test.txt");
  for(int i; i<N; i++){
    text<<test.parts[0].r << test.parts[1].r <<"\n";
    test.evolve_Euler(dt);
  }
  return 0;
  text.close();
}
