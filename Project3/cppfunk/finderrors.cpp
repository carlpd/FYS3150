#include "../hppfunk/p3.hpp"

arma::vec abserr(arma::vec t, arma::vec an, arma::vec num){
  arma::vec aber=num.size();
  for(i=0; i<num.size){
    arma::vec err=num(i)-an(i);
    arma::vec aber=((err(0)*err(0))+(err(1)*err(1))+(err(2)*err(2)));
  }
}
arma::vec relerr(arma::vec t, arma::vec an, arma::vec num){
  arma::vec reerr=num.size();
}
