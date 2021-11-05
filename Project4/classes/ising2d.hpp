#include <iostream>
#include <armadillo>
#include <cmath>

class Ising2d{
  public:
    arma::imat S;
    double T;
    int L;
    int N = L*L;
    int seed = 4832;
    int ep;
    int ep2;
    int M;
    int M2;
    double Cv;
    double X;
    Ising2d(double T_in, int L_in);

    /*arma_rng::set_seed(4832); Endre til bedre random */

    int epsrun = 0;
    int magrun = 0;
    int CvRun = 0;
    int Xrun = 0;
    arma::vec bf=arma::vec(17).fill(0.);
    arma::imat makerandomspins();
    arma::imat makeallupspins();
    arma::imat S_new;
    void findeps();
    void findmag();
    void findCv();
    void findX();
    void findall();
    int FindDelS(int i, int j);
    void findrandomspin(int &i, int &j);
    void makebflist();

};
