#include "../classes/ising2d.hpp"
#include <fstream>
#include <chrono>
#include <omp.h>


int main(){
  int TN=10;
  double Tstart=2.2;
  double Tend=2.4;
  int LN=4;
  int Lstart=40;
  int Lend=100;
  std::string filename;
  filename="Txt/dummy.txt";
  std::ofstream f (filename, std::ofstream::out);
  arma::vec T=arma::linspace(Tstart, Tend, TN);
  std::ofstream TimePar ("Txt/Time.txt", std::ios::app);
  auto t1 = std::chrono::high_resolution_clock::now();
  //#pragma omp parallel for
  for(int Ti=0;Ti<T.n_elem;Ti++){
    double T_in = T(Ti); /* [J/kb] */
    std::cout<<T_in<<std::endl;
    int omp_get_thread_num();
    int L_in = 10; /* [-] */

    Ising2d IS2D = Ising2d(T_in, L_in);
    int NumThread = omp_get_thread_num();
    double DivRand =(T_in*L_in*NumThread)/34;
    arma::imat dummyS = IS2D.makerandomspins(DivRand);

    IS2D.findall();
    int samplestart=1000;
    //std::cout<<"N"<<IS2D.N_<<std::endl;
    int samplen=5000;
    std::cout<<"N"<<IS2D.N_<<std::endl;
    std::cout<<"end"<<samplen<<std::endl;
    for(int a=0; a<=samplestart; a++){
      for(int b=0; b<=IS2D.N_; b++){
        IS2D.makebreakstate();
      }
    }
    std::cout<<"out"<<std::endl;
    double TE=0;
    double TE2=0;
    double TM=0;
    double TM2=0;
    for(int c=samplestart; c<=samplen; c++){
      for(int d=0; d<=IS2D.N_; d++){
        //std::cout<<TE<<std::endl;
        IS2D.makebreakstate();
        TE+=IS2D.ep_;
        TE2+=IS2D.ep2_;
        TM+=IS2D.M_;
        TM2+=IS2D.M2_;
      }
    }
    std::cout<<"Kom seg hit"<<std::endl;
    int sampledif=(samplen-samplestart)*IS2D.N_;
    TE=TE/(sampledif);
    TE2=TE2/(sampledif);
    TM=TM/(sampledif);
    TM2=TM2/(sampledif);

    // Step | eps | eps^2 | m | m^2
    f << T_in << " " << TE << " " << TE2 << " ";
    f << TM << " " << TM2 << std::endl;
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  double duration_seconds = std::chrono::duration<double>(t2 - t1).count();
  TimePar << duration_seconds << std::endl;
  TimePar.close();
  f.close();
  return 0;
}
