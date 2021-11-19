#include "../classes/ising2d.hpp"
#include <fstream>
#include <chrono>
#include <omp.h>


int main(){
  //arma::vec T=arma::vec(2).fill(0.);
  //arma::vec L=arma::vec(2).fill(0.);
  int TN=100;
  double Tstart=2.1;
  double Tend=2.4;
  int LN=4;
  int Lstart=40;
  int Lend=100;
  std::string filename;
  filename="Txt/PerTemp.txt";
  std::ofstream f (filename, std::ofstream::out);
  arma::vec T=arma::linspace(Tstart, Tend, TN);
  #pragma omp parallel for
  for(int Ti=0;Ti<T.n_elem;Ti++){
    double T_in = T(Ti); /* [J/kb] */
    int omp_get_thread_num();
    int L_in = 100; /* [-] */
    Ising2d IS2D = Ising2d(T_in, L_in);
    int NumThread = omp_get_thread_num();
    double DivRand =(T_in*L_in*NumThread)/34;
    arma::imat dummyS = IS2D.makerandomspins(DivRand);
    //std::cout<<IS2D.S_<<std::endl;
    IS2D.findall();
    /*
    double deps = IS2D.ep/IS2D.N; double deps2 = IS2D.ep2/(IS2D.N*IS2D.N);
    double m = IS2D.M/IS2D.N; double m2 = IS2D.M2/IS2D.N;
    // Step | eps | eps^2 | m | m^2 | Cv | X
    f << 1 << " " << deps << " " << deps2 << " ";
    f << m << " " << m2 << " " << IS2D.Cv << " " << IS2D.X << std::endl;
    */
    for(int a=0; a<=IS2D.N_*1000; a++){
      // Step | eps | eps^2 | m | m^2
      IS2D.makebreakstate();
      //std::cout<<IS2D.S_<<std::endl;
    }
    for(int a=IS2D.N_*1000; a<=IS2D.N_*500000; a++){
      // Step | eps | eps^2 | m | m^2
      IS2D.makebreakstate();
      //std::cout<<IS2D.S_<<std::endl;
    }
    f << T_in << " " << IS2D.ep_ << " " << IS2D.ep2_ << " ";
    f << IS2D.M_ << " " << IS2D.M2_ << std::endl;
  }
  f.close();
  return 0;
}
