#include "../classes/ising2d.hpp"
#include <fstream>
#include <omp.h>

int main(){
  //std::ofstream Time ("Txt/Time.txt", std::ios::app);
  //std::ofstream Ttxt ("Txt/T.txt", std::ofstream::out);
  //std::ofstream Ltxt ("Txt/L.txt", std::ofstream::out);
  //auto t1 = std::chrono::high_resolution_clock::now();
    double T_in = 2.4; /* [J/kb] */
    //Ttxt << std::to_string(T_in) << std::endl;

    */
    double T_in=1.0;
    int L_in = 10; /* [-] */


    int L_in = 20; /* [-] */
    std::string filename;
    filename="Txt/ChainT" + std::to_string(T_in) + "L" + std::to_string(L_in) + ".txt";
    std::ofstream f (filename, std::ofstream::out);

    Ising2d IS2D = Ising2d(T_in, L_in);
    arma::imat dummyS = IS2D.makeallupspins();
    //std::cout<<IS2D.S_<<std::endl;
    IS2D.findall();
    /*
    double deps = IS2D.ep/IS2D.N; double deps2 = IS2D.ep2/(IS2D.N*IS2D.N);
    double m = IS2D.M/IS2D.N; double m2 = IS2D.M2/IS2D.N;
    // Step | eps | eps^2 | m | m^2 | Cv | X
    f << 1 << " " << deps << " " << deps2 << " ";
    f << m << " " << m2 << " " << IS2D.Cv << " " << IS2D.X << std::endl;
    */
    /*
    for(int a=0; a<=IS2D.N_*1000; a++){
      // Step | eps | eps^2 | m | m^2
      IS2D.makebreakstate();
      //std::cout<<IS2D.S_<<std::endl;
    }
    */

    for(int a=0; a<=IS2D.N_*10000; a++){
      // Step | eps | eps^2 | m | m^2
      f << a << " " << IS2D.ep_ << " " << IS2D.ep2_ << " ";
      f << IS2D.M_ << " " << IS2D.M2_ <<std::endl;
      IS2D.makebreakstate();
      //std::cout<<IS2D.S_<<std::endl;
  }
  f.close();
  return 0;
}
