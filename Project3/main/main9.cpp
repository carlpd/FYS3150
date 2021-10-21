#include "../hppfunk/p3.hpp"
#include <fstream>
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;

int main(){
  double tV0=10.0*Volt;
  double tB0=1.0*Tesla;
  double td=1e4;
  double q1=1.0;
  double m1=20.0;
  arma::vec pr1=arma::vec(3).fill(0.);
  arma::vec pv1=arma::vec(3).fill(0.);
  pr1={1.0, -1.0, 0.0};
  pv1={-1.0, 0.0, 0.0};
  Particle p1(q1, m1, pr1, pv1);
  //Particle first_particle(q,m,r,v);
  //PenningTrap.add_particle(first_particle);
  std::vector<class Particle> tparts;
  PenningTrap part1=PenningTrap(tB0, tV0, td, tparts);

  part1.add_particle(p1);

  //test.add_particle(p1);
  //test.add_particle(p2);
  //test.add_particle(p3);
  double tmax=100;
  double dt=0.001;
  int N=(int)(tmax/dt);
  arma::vec t=arma::linspace(0, tmax, N );
  std::ofstream r1;
  std::ofstream wz1;
  r1.open("../Txtfiler/r1.txt");
  wz1.open("../Txtfiler/wz1.txt");
  for(int i=0; i<N; i++){
    std::cout<<t(i)<<std::endl;
    r1<<t(i)<<" "<<part1.parts[0].r(0) <<" "<< part1.parts[0].r(1)<<" " <<part1.parts[0].r(2)<<std::endl;
    double wz=part1.parts[0].m *part1.parts[0].v(2);
    wz1<<t(i)<<" "<<wz<<std::endl;
    part1.evolve_RK4(dt);
  }
  r1.close();
  wz1.close();
  std::vector<class Particle> tparts2;
  PenningTrap part2=PenningTrap(tB0, tV0, td, tparts2);
  // Lager noen partikler
  arma::vec pr2=arma::vec(3).fill(0.);
  arma::vec pv2=arma::vec(3).fill(0.);
  pr2={-1.0, -1.0, 0.0};
  pv2={1.0, 0.0, 0.0};
  Particle p2(q1,m1, pr2, pv2);
  part2.add_particle(p1);
  part2.add_particle(p2);
  part2.partint=false;
  std::ofstream r2;
  r2.open("../Txtfiler/r2noint.txt");
  std::ofstream v2;
  v2.open("../Txtfiler/v2noint.txt");
  for(int i=0; i<N; i++){
    std::cout<<t(i)<<std::endl;
    r2<<t(i)<<" "<<part2.parts[0].r(0) <<" "<< part2.parts[0].r(1)<<" "<<part2.parts[0].r(2)<<" "<<part2.parts[1].r(0) <<" "<< part2.parts[1].r(1)<<" "<<part2.parts[1].r(2)<<std::endl;
    v2<<t(i)<<" "<<part2.parts[0].v(0) <<" "<< part2.parts[0].v(1)<<" "<<part2.parts[0].v(2)<<" "<<part2.parts[1].v(0) <<" "<< part2.parts[1].v(1)<<" "<<part2.parts[1].v(2)<<std::endl;
    part2.evolve_RK4(dt);
  }
  r2.close();
  v2.close();
  PenningTrap part3=PenningTrap(tB0, tV0, td, tparts2);
  part3.add_particle(p1);
  part3.add_particle(p2);
  std::ofstream r3;
  std::ofstream v3;
  r3.open("../Txtfiler/r2int.txt");
  v3.open("../Txtfiler/v2int.txt");
  for(int i=0; i<N; i++){
    std::cout<<t(i)<<std::endl;
    r3<<t(i)<<" "<<part3.parts[0].r(0) <<" "<< part3.parts[0].r(1)<<" "<<part3.parts[0].r(2)<<" "<<part3.parts[1].r(0) <<" "<< part3.parts[1].r(1)<<" "<<part3.parts[1].r(2)<<std::endl;
    v3<<t(i)<<" "<<part3.parts[0].v(0) <<" "<< part3.parts[0].v(1)<<" "<<part3.parts[0].v(2)<<" "<<part3.parts[1].v(0) <<" "<< part3.parts[1].v(1)<<" "<<part3.parts[1].v(2)<<std::endl;
    part3.evolve_RK4(dt);
  }
  r3.close();
  v3.close();
  return 0;
}
