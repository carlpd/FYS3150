#include <iostream>
#include <armadillo>
#include <chrono>
#include <cmath>
#include <random>



class Ising2d{

  public:

    std::mt19937_64 gen;
    int seed_ = 404040;
    arma::imat S_;
    double T_;
    int L_;
    int N_;
    double ep_;
    double Ninv_;
    double ep2_;
    double M_;
    double M2_;
    double Cv_;
    double X_;
    Ising2d(double T_in, int L_in);


    int epsrun_ = 0;
    int magrun_ = 0;
    int CvRun_ = 0;
    int Xrun_ = 0;
    arma::vec bf_=arma::vec(17).fill(0.);
    arma::imat makerandomspins();
    arma::imat makeallupspins();
    arma::imat S_new_;
    void findeps();
    void findmag();
    void findCv();
    void findX();
    void findall();
    int FindDelE(int i, int j);
    void findrandomspin(int &i, int &j);
    void makebflist();
    double Rng();
    double Ap(int dE);
    void makebreakstate();

};
