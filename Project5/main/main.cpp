#include "../hpp/AllFunks.hpp"

int main(){
  double h=0.02;
  double dt=2.5e-5;
  double T=0.008;
  double xc=0.25;
  double sigx=0.05;
  double px=200;
  double yc=0.5;
  double sigy=0.05;
  double py=0;
  double v0=0;
  int sz=1/h+1;
  std::cout<<"sz"<<sz<<std::endl;
  int sz2=sz*sz;
  int sl=2;
  int Nt=T/dt;
  arma::cx_double r=(0,dt/(2*h*h));
  std::cout << "main1" << std::endl;
  arma::vec v=makeV(sz, sl);
  arma::mat V=BackToRealMat(v);
  V.print("V");
  std::cout << "main2" << std::endl;
  arma::cx_vec u=makeinit(sz, sigx, sigy, xc, yc, px, py);
  //u.print("u");
  std::cout << "main3" << std::endl;
  arma::sp_cx_mat A=arma::sp_cx_mat(sz2,sz2);
  //A.print("A");
  std::cout << "main4" << std::endl;
  arma::sp_cx_mat B=arma::sp_cx_mat(sz2,sz2);
//  B.print("B");
  std::cout << "main5" << std::endl;
  arma::cx_vec aa=makea(sz, v, r, dt);
  arma::cx_vec bb=makeb(sz, v, r, dt);
  MakeAB(A,  B, aa, bb, r);
  arma::cx_cube Ut=arma::cx_cube(sz, sz, Nt);
  Ut.slice(0)=BackToMat(u);
  std::cout << "main6" << std::endl;
  for(int nt=0; nt<(Nt-1); nt++){
    //std::cout << "B" <<B.n_cols<< std::endl;
    //std::cout << "u" <<u.n_elem<< std::endl;
    arma::cx_vec b=findb(B, u);
    //std::cout << "unew" << std::endl;
    arma::cx_vec u=findu_new(A,b);
    //std::cout << "Unew" << std::endl;
    arma::cx_mat U_new=BackToMat(u);
    Ut.slice(nt+1)=U_new;
  }
  //Ut.save("../txt/U1.bin");
  return 0;
}
