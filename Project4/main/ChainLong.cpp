#include "../classes/ising2d.hpp"
#include <fstream>
#include <chrono>
#include <omp.h>


int main(){
  int TN=100;
  double Tstart=2.1;
  double Tend=2.4;
  int LN=4;
  int Lstart=40;
  int Lend=100;
  std::string filename;
  filename="Txt/PerTemp40.txt";
  std::ofstream f (filename, std::ofstream::out);
  arma::vec T=arma::linspace(Tstart, Tend, TN);
  #pragma omp parallel for
  for(int Ti=0;Ti<T.n_elem;Ti++){
    double T_in = T(Ti); /* [J/kb] */
    std::cout<<T_in<<std::endl;
    int omp_get_thread_num();
    int L_in = 40; /* [-] */

    Ising2d IS2D = Ising2d(T_in, L_in);
    int NumThread = omp_get_thread_num();
    double DivRand =(T_in*L_in*NumThread)/34;
    arma::imat dummyS = IS2D.makerandomspins(DivRand);

    IS2D.findall();
    float samplestart=1000*1.0*IS2D.N_;
    //std::cout<<"N"<<IS2D.N_<<std::endl;
    float samplen=IS2D.N_*1.0*500000;
    std::cout<<"N"<<IS2D.N_<<std::endl;
    std::cout<<"end"<<samplen<<std::endl;
    for(float a=0; a<=samplestart; a++){
      IS2D.makebreakstate();
    }
    double TE=0;
    double TE2=0;
    double TM=0;
    double TM2=0;
    for(float b=samplestart; b<=samplen; b++){
      //std::cout<<TE<<std::endl;
      IS2D.makebreakstate();
      TE+=IS2D.ep_;
      TE2+=IS2D.ep2_;
      TM+=IS2D.M_;
      TM2+=IS2D.M2_;

    }
    std::cout<<"Kom seg hit"<<std::endl;
    int sampledif=(samplen-samplestart);
    TE=TE/(sampledif);
    TE2=TE2/(sampledif);
    TM=TM/(sampledif);
    TM2=TM2/(sampledif);

    // Step | eps | eps^2 | m | m^2
    f << T_in << " " << TE << " " << TE2 << " ";
    f << TM << " " << TM2 << std::endl;
  }
  f.close();
  return 0;
}
