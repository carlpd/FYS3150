#include <armadillo>

class Particle{
public:
  double q; //Charge
  double m; //Mass
  arma::vec r; //position
  arma::vec v; //Velocity
};
class PenningTrap{
public:
  double B0;
  double V0;
  double d;
}
