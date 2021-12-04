#include "../hpp/Makeinitstate.hpp"

arma::cx_double makegaus(arma::cx_double x, double sig, double mu, double kx){
  return exp(-1*(x-mu)*(x-mu)/(sig*sig*2))*exp(std::complex(0+ikx*x));
}

arma::cx_vec makeinit(arma::cx_vec u, double sigx, double sigy, double mux, double muy, double kx, double ky){
  
}
