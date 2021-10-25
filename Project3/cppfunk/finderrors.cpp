#include "../hppfunk/p3.hpp"
#include "../hppfunk/finderrors.hpp"
double ke=1.38935333e5;
double Tesla=9.64852558e1;
double Volt=9.64852558e7;
double V0=10.0*Volt;
double B0=1.0*Tesla;
double td=1e4;
double q=1.0;
double m=20.0;
double abserr(arma::vec an, arma::vec num){
  double aber=arma::norm(an-num, 2);
  aber=std::abs(aber);
  /*
  arma::vec aber=arma::vec(num.size()).fill(0.0);
  for(int i=0; i<num.size(); i++){
    double err=num(i)-an(i);
    aber(i)=((err*err+(err*err(1))+(err(2)*err(2)));
  }*/
  return aber;
}
double relerr(arma::vec an, arma::vec num){
  double aber=abserr(an, num);
  double reerr=aber/std::abs(arma::norm(an,2));
  return reerr;
}
arma::vec analytical(double t, Particle p1){
  double x0=p1.r(0);
  double y0=p1.r(1);
  double z0=p1.r(2);
  double v0=1.0;
  double d = 1e4; //sqrt(z0**2 + (x0**2 + y0**2 + z0**2)/2)
  double oz = std::sqrt(2*std::abs(q)*V0/(m*d*d));
  double o0 = std::abs(q)*B0/m;
  double oP = (o0+std::sqrt(o0*o0-2*oz*oz))/2;
  double oM = (o0-std::sqrt(o0*o0-2*oz*oz))/2;
  double AP = (v0 + oM*x0)/(oM-oP);
  double AM = (-1)*(v0 + oP*x0)/(oM-oP);
  //double std::complex<double> i1=(0, (-oz)*t);
  double wz=2*q*v0/(m*d*d);
  double z= z0*std::cos(wz*t);//z0/2*std::exp(i1) + z0/2*std::exp(i1);
  double x=AP*std::cos(oP*t)+AM*std::cos(oM*t);
  double y=(-AP)*std::sin(oP*t)-AM*std::sin(oM*t);
  arma::vec rn=arma::vec(3).fill(0.);
  rn={x,y,z};
  return rn;
}

void makeRK4txt(Particle p1, double dt ,int i){
  std::vector<class Particle> parts;
  PenningTrap part=PenningTrap(B0, V0, td, parts);
  part.add_particle(p1);
  double tmax=100;
  int N=(int)(tmax/dt);
  arma::vec t=arma::linspace(0, tmax, N );
  std::ofstream er; //RungeKutta 4
  er.open("../Txtfiler/err"+std::to_string(i)+"RK4.txt");
  er<<"#"<<"time"<<" "<<"Analytical x"<<" "<<"Analytical y"<<" "<<"Analytical z"<<" "<<"Numerical x"<<" "<<"Numerical y"<<" "<<"Numerical z"<<" "<<"Absolute Error"<<" "<<"Relative Error"<<std::endl;
  for(int i=0;i<t.size();i++){
    arma::vec num=part.parts[0].r;
    arma::vec an=analytical(t(i), p1);
    double reerr=relerr(an, num);
    double aberr=abserr(an, num);
    er<<t(i)<<" "<<an(0)<<" "<<an(1)<<" "<<an(2)<<" "<<num(0)<<" "<<num(1)<<" "<<num(2)<<" "<<aberr<<" "<<reerr<<std::endl;
    part.evolve_RK4(dt);
  }
  er.close();
}
void makeEulertxt(Particle p1, double dt, int i){
  std::vector<class Particle> parts;
  PenningTrap part=PenningTrap(B0, V0, td, parts);
  part.add_particle(p1);
  double tmax=100;
  int N=tmax/dt;
  arma::vec t=arma::linspace(0, tmax, N );
  std::ofstream er;
  er.open("../Txtfiler/err"+std::to_string(i)+"Euler.txt");
  er<<"#"<<"time"<<" "<<"Analytical x"<<" "<<"Analytical y"<<" "<<"Analytical z"<<" "<<"Numerical x"<<" "<<"Numerical y"<<" "<<"Numerical z"<<" "<<"Absolute Error"<<" "<<"Relative Error"<<std::endl;
  for(int i=0;i<t.size();i++){
    arma::vec num=part.parts[0].r;
    arma::vec an=analytical(t(i), p1);
    double reerr=relerr(an, num);
    double aberr=abserr(an, num);
    er<<t(i)<<" "<<an(0)<<" "<<an(1)<<" "<<an(2)<<" "<<num(0)<<" "<<num(1)<<" "<<num(2)<<" "<<aberr<<" "<<reerr<<std::endl;
    part.evolve_Euler(dt);
  }
  er.close();
}
/*
std::vector<arma::vec> FindErrors(arma::vec an, arma::vec num){
  arma::vec aber=abserr(an, num);

}*/
