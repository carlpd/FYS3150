#include "../classes/ising2d.hpp"
#include <fstream>

int main(){
  arma::vec T=arma::vec(2).fill(0.);
  T(0)=1.0;
  T(1)=2.4;
  for(int Ti=0;Ti<T.n_elem;Ti++){
    double T_in = T(Ti); /* [J/kb] */
    int L_in = 20; /* [-] */
    std::string filename;
    filename="../Txt/ChainT" + std::to_string(T_in) + "L" + std::to_string(L_in) + ".txt";
    std::ofstream f (filename, std::ofstream::out);

    Ising2d IS2D = Ising2d(T_in, L_in);
    arma::imat dummyS = IS2D.makerandomspins();
    //std::cout<<IS2D.S_<<std::endl;
    IS2D.findall();
    /*
    double deps = IS2D.ep/IS2D.N; double deps2 = IS2D.ep2/(IS2D.N*IS2D.N);
    double m = IS2D.M/IS2D.N; double m2 = IS2D.M2/IS2D.N;
    // Step | eps | eps^2 | m | m^2 | Cv | X
    f << 1 << " " << deps << " " << deps2 << " ";
    f << m << " " << m2 << " " << IS2D.Cv << " " << IS2D.X << std::endl;
    */

    for(int a=0; a<=20000; a++){
      // Step | eps | eps^2 | m | m^2
      IS2D.makebreakstate();
      //std::cout<<IS2D.S_<<std::endl;
    }
    for(int a=20000; a<=100000; a++){
      // Step | eps | eps^2 | m | m^2
      f << a << " " << IS2D.ep_ << " " << IS2D.ep2_ << " ";
      f << IS2D.M_ << " " << IS2D.M2_ <<std::endl;
      IS2D.makebreakstate();
      //std::cout<<IS2D.S_<<std::endl;
    }
    f.close();
  }
  return 0;
}
