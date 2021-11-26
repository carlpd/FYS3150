#include "../hpp/FindJMakeAB.hpp"

// u_1,1 , u_2,1 , u_1,2, u_2,2
// Teller gjennom antall i i en rad, gir k = i + j*(M-2)

int FindK(int i, int j, int M){
  int k =  i + j*(M-2);
  return k;
}
/*
void MakeAB(arma::cx_mat& A, arma::cx_mat& B, arma::cx_vec a, arma::cx_vec b, arma::cx_double r){
  for (int i = 0; i<((M-2)*(M-2));i++){
    A(i, i) = a(i); B(i,i) = b(i);
  }
  for (int i = 0; i<((M-2)*(M-2)-1);i++){
    A(i, i+1) = -r; B(i, i+1) = r;
    A(i+1, i) = -r; B(i+1, i) = r;
  }
  A(3, 2) = 0; B(3, 2) = 0;
  A(2, 3) = 0; B(2, 3) = 0;
  A(5, 6) = 0; B(5, 6) = 0;
  A(6, 5) = 0; B(6, 5) = 0;

  for (int i = 0; i<6; i++){
    A(i+3, i) = -r; B(i+3, i) = r;
    A(i, i+3) = -r; B(i, i+3) = r;
  }
}
*/
void MakeABC(arma::cx_mat& A,  arma::cx_mat& B, arma::cx_vec a, arma::cx_vec b, arma::cx_double r){
  int Mm2=a.n_elem;
  int sMm2=sqrt(Mm2);
  arma::cx_mat R=arma::cx_mat(sMm2, sMm2).fill(0.);
  for(int j=0; j<sMm2; j++){
    R(j,j)=r;
  }
  std::cout<<"Lagde R"<<std::endl;
  std::cout<<R<<std::endl;
  arma::cx_mat P=arma::cx_mat(sMm2, sMm2).fill(0.);
  for(int j=0; j<(sMm2-1);j++){
    P(j+1,j)=r;
    P(j,j+1)=r;
  }
  std::cout<<"Lagde P"<<std::endl;
  std::cout<<P<<std::endl;
  for(int h=0; h<sMm2;h++){
    for(int i=0; i<sMm2;i++){
      for(int j=0; j<sMm2;j++){
        A(h*sMm2+i, h*sMm2+j)=-P(i,j);
      }
    }
  }
  std::cout<<"Satte inn R"<<std::endl;
  std::cout<<A<<std::endl;
  for(int h=0; h<(sMm2-1);h++){
    for(int i=0; i<sMm2;i++){
      for(int j=0; j<sMm2;j++){
        A((h+1)*sMm2+i,h*sMm2+j)=(-R(i,j));
        A(h*sMm2+i, (h+1)*sMm2+j)=(-R(i,j));
        B((h+1)*sMm2+i,h*sMm2+j)=R(i,j);
        B(h*sMm2+i, (h+1)*sMm2+j)=R(i,j);
      }
    }
  }
  std::cout<<"Satte inn P"<<std::endl;
  std::cout<<A<<std::endl;
  for(int i=0; i<Mm2; i++){
    A(i,i)=a(i);
    B(i,i)=b(i);
  }
}
