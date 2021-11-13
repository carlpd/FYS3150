#include "../classes/ising2d.hpp"
#include <fstream>

int main(){
  arma::vec T=arma::vec(2).fill(0.);
  arma::vec L=arma::vec(2).fill(0.);
  T(0)=1.0; T(1)=2.4;
  L(0)=20; L(1)=40;
  std::ofstream Ttxt ("../Txt/T.txt", std::ofstream::out);
  std::ofstream Ltxt ("../Txt/L.txt", std::ofstream::out);
  for(int Ti=0;Ti<T.n_elem;Ti++){
    double T_in = T(Ti); /* [J/kb] */
    Ttxt << std::to_string(T_in) << std::endl;
    for(int Li=0;Li<L.n_elem;Li++){


      int L_in = L(Li); /* [-] */

      Ltxt << std::to_string(L_in) << std::endl;

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
    Ttxt.close();
    Ltxt.close();
  }
  return 0;
}
