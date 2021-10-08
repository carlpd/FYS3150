#include "../hppfunk/p3.hpp"
#include <fstream>
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;

int main(){
  double tV0=10.0*Volt;
  double tB0=1.0*Tesla;
  double td=1e4;
  double q1=ke;
  double m1=1;
  arma::vec r1=arma::vec(3).fill(0.);
  arma::vec r2=arma::vec(3).fill(0.);
  arma::vec r3=arma::vec(3).fill(0.);
  arma::vec v1=arma::vec(3).fill(0.);
  arma::vec v2=arma::vec(3).fill(0.);
  arma::vec v3=arma::vec(3).fill(0.);
  r1(0)=-td/2;
  r1(1)=-td/2;
  r1(2)=-td/2;
  r2(0)=td/2;
  r2(1)=td/2;
  r2(2)=td/2;
  r3(0)=td/2;
  r3(1)=-td/2;
  r3(2)=td/2;
  v1(0)=0.2*td;
  v1(1)=0.2*td;
  v1(2)=0.2*td;
  v2(0)=-0.2*td;
  v2(1)=-0.2*td;
  v2(2)=-0.2*td;
  v3(0)=-0.2*td;
  v3(1)=0.2*td;
  v3(2)=-0.2*td;
  Particle p1(q1,m1, r1, v1);
  Particle p2(q1,m1, r2, v2);
  Particle p3(q1,m1, r3, v3);

  //Particle first_particle(q,m,r,v);
  //PenningTrap.add_particle(first_particle);
  std::vector<class Particle> tparts;
  PenningTrap test=PenningTrap(tV0, tB0, td, tparts);
  /*
  test.add_randomparticle();
  test.add_randomparticle();
  */
  test.add_particle(p1);
  test.add_particle(p2);
  //test.add_particle(p3);
  int N=100;
  arma::vec t=arma::linspace(0, 10, N);
  double dt=10/(N+1);
  std::ofstream text;
  text.open("../Txtfiler/test.txt");
  for(int i=0; i<N; i++){
    std::cout<<"Her"<<std::endl;
    text<<test.parts[0].r(0) <<" "<< test.parts[0].r(1)<<" "<< test.parts[1].r(0)<<" " <<test.parts[1].r(1) <<"\n";
    test.evolve_Euler(dt);
  }
  return 0;
  text.close();
}
