#include "../hppfunk/p3.hpp"
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;

int main(){

  Particle first_particle(q,m,r,v)
  //PenningTrap.add_particle(first_particle)

  tV0=10.0*Volt;
  tB0=1.0*Tesla;
  td=1e4;
  std::vector<class Particle> tparts;
  PenningTrap test=Penningtrap(tV0, tB0, td, tparts);
  test.add_randomparticle();
  return 0;
}
