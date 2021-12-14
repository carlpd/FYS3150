#include "../hpp/AllFunks.hpp"

int main(){
  arma::vec sl1={0., 0.475, 0.525, 1.0};
  arma::vec sl2={0., 0.425, 0.475, 0.525, 0.575, 1.0};
  arma::vec sl3={0.0, 0.375, 0.425, 0.475, 0.525, 0.575, 0.625, 1.0};
  std::vector<arma::vec> sls={sl1, sl2, sl3};
  int sln = 2;
  double h=0.005;
  double dt=2.5e-5;
  double T=0.002;
  double xc=0.25;
  double sigx=0.05;
  double px=200;
  double yc=0.5;
  double sigy=0.1;
  double py=0;
  double v0=std::pow(10.,10.);
  int sz=1/h-1;
  //int sz=4;
  std::cout<<"sz"<<sz<<std::endl;
  int sz2=sz*sz;
  int sl=sln;
  int Nt=T/dt;
  arma::cx_double r = arma::cx_double(0., dt / (2*h*h));
  arma::vec v=makeV(sz, sl, sls[sln-1], v0);
  arma::mat V=BackToRealMat(v);
  arma::cx_vec u=makeinit(sz, sigx, sigy, xc, yc, px, py, h);
  arma::sp_cx_mat A=arma::sp_cx_mat(sz2,sz2);
  arma::sp_cx_mat B=arma::sp_cx_mat(sz2,sz2);
  arma::cx_vec aa=makea(sz, v, r, dt);
  arma::cx_vec bb=makeb(sz, v, r, dt);
  MakeAB(A,  B, aa, bb, r);
  arma::cx_cube Ut=arma::cx_cube(sz, sz, Nt);
  arma::vec P=arma::vec(Nt).fill(0.);
  Ut.slice(0)=BackToMat(u);
  for(int nt=0; nt<(Nt-1); nt++){
    P(nt)=FindP(u);
    arma::cx_colvec b=findb(B, u);
    u=findu_new(A,b);
    arma::cx_mat U_new=BackToMat(u);
    Ut.slice(nt+1)=U_new;
  }

  P.save("./txt/7s1P1"+std::to_string(sz)+std::to_string(sln)+".bin");
  Ut.save("./txt/7s1U1"+std::to_string(sz)+std::to_string(sln)+".bin");
  return 0;
}
