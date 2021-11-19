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
  arma::vec T=arma::linspace(Tstart, Tend, TN);
  std::ofstream TimePar ("Txt/TimePar.txt", std::ios::app);
  std::ofstream Ttxt ("Txt/T.txt", std::ofstream::out);
  std::ofstream Ltxt ("Txt/L.txt", std::ofstream::out);
  auto t1 = std::chrono::high_resolution_clock::now();
  #pragma omp parallel for
  for(int Ti=0;Ti<T.n_elem;Ti++){
    double T_in = T(Ti); /* [J/kb] */
    //std::cout<<T_in<<std::endl;
    Ttxt << std::to_string(T_in) << std::endl;
    int omp_get_thread_num();
    int L_in = 60; /* [-] */

    Ltxt << std::to_string(L_in) << std::endl;

    std::string filename;
    filename="../Txt/ChainT" + std::to_string(T_in) + "L" + std::to_string(L_in) + ".txt";
    std::ofstream f (filename, std::ofstream::out);

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
      //std::cout<<a<<std::endl;
    }
    for(int a=IS2D.N_*1000; a<=IS2D.N_*500000; a++){
      // Step | eps | eps^2 | m | m^2
      f << a << " " << IS2D.ep_ << " " << IS2D.ep2_ << " ";
      f << IS2D.M_ << " " << IS2D.M2_ <<std::endl;
      IS2D.makebreakstate();
      //std::cout<<a<<std::endl;
    }
    f.close();

  }
  Ttxt.close();
  Ltxt.close();

  auto t2 = std::chrono::high_resolution_clock::now();
  double duration_seconds = std::chrono::duration<double>(t2 - t1).count();
  TimePar << duration_seconds << std::endl;
  TimePar.close();
  return 0;
}
