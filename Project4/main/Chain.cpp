#include "../classes/ising2d.hpp"
#include <fstream>
#include <omp.h>

int main(){
    double T_in=2.4;
    int L_in = 20; /* [-] */

    int L_in = 20; /* [-] */
    std::string filename;
    filename="Txt/ChainT" + std::to_string(T_in) + "L" + std::to_string(L_in) + ".txt";
    std::ofstream f (filename, std::ofstream::out);

    Ising2d IS2D = Ising2d(T_in, L_in);
    arma::imat dummyS = IS2D.makeallupspins();
    IS2D.findall();


    for(int a=0; a<=IS2D.N_*10000; a++){
      f << a << " " << IS2D.ep_ << " " << IS2D.ep2_ << " ";
      f << IS2D.M_ << " " << IS2D.M2_ <<std::endl;
      IS2D.makebreakstate();
    }
  f.close();
  return 0;
}
