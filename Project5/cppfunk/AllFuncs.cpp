#include "../hpp/AllFunks.hpp"
//Liten greie for å finne k ene i u-vektoren
int FindK(int i, int j, int sz){
  int k =  i + j*sz;
  return k;
}
//Lager et gaussisk element
arma::cx_double makegaus(double x, double sig, double mu, double kx){
  arma::cx_double i=arma::cx_double(0.0,1.0);
  double xmu=x-mu;
  return exp((-1.)*xmu*xmu/(sig*sig*2))*exp(i*kx*(xmu));
}
//Setter sammen en gaussisk initialtilstand, ikke ferdig, sz er størrelsen(size) av u, altså M-2
arma::cx_vec makeinit(int sz, double sigx, double sigy, double mux, double muy, double kx, double ky, double h){
  int sz2=sz*sz;
  arma::cx_vec u_in=arma::cx_vec(sz2).fill(0.);
  arma::vec xy=arma::linspace(0+h,1-h,sz);
  for(int i=0; i<sz; i++){
    arma::cx_double fx=makegaus(xy(i), sigx, mux, kx);
    for(int j=0; j<sz; j++){
      arma::cx_double fy=makegaus(xy(j), sigy, muy, ky);
      int k=FindK(i,j, sz);
      u_in(k)=fx*fy;
    }
  }
  //Normaliserer
  arma::vec P=arma::real(u_in)%arma::real(u_in) + arma::imag(u_in)%arma::imag(u_in);
  u_in=u_in/sqrt(arma::accu(P));
  P=arma::real(u_in)%arma::real(u_in) + arma::imag(u_in)%arma::imag(u_in);
  return u_in;
}
//Lager diagonalen til A
arma::cx_vec makea(int sz, arma::vec v, arma::cx_double r, double dt){
  int sz2=sz*sz;
  arma::cx_vec a=arma::cx_vec(sz2).fill(0.);
  for(int i=0; i<sz; i++){
    for(int j=0;j<sz; j++){
      int k =FindK(i, j, sz);
      a(k)=1.+4. * r+ (0.+1.0i) * dt * v(k)/2.;
    }
  }
  return a;
}
//Lager diagonalen til B
arma::cx_vec makeb(int sz, arma::vec v, arma::cx_double r, double dt){
  int sz2=sz*sz;
  arma::cx_vec b=arma::cx_vec(sz2).fill(0.);
  for(int i=0; i<sz; i++){
    for(int j=0;j<sz; j++){
      int k =FindK(i, j, sz);
      b(k)=1.-4.*r-(0.+1.0i)*dt*v(k)/2.;
    }
  }
  return b;
}
//Lager A og B
void MakeAB(arma::sp_cx_mat& A,  arma::sp_cx_mat& B, arma::cx_vec a, arma::cx_vec b, arma::cx_double r){
  int sz2=a.n_elem;
  int sz=sqrt(sz2);
  //Lager matrisen som settes under og til høyre for P
  arma::cx_mat R=arma::cx_mat(sz, sz).fill(0.);
  for(int j=0; j<sz; j++){
    R(j,j)=r;
  }
  //Lager matrisen på som settes diagonalt nedover
  arma::cx_mat P=arma::cx_mat(sz, sz).fill(0.);
  for(int j=0; j<(sz-1);j++){
    P(j+1,j)=r;
    P(j,j+1)=r;
  }
  //Setter inn P
  for(int h=0; h<sz;h++){
    for(int i=0; i<sz;i++){
      for(int j=0; j<sz;j++){
        A(h*sz+i, h*sz+j)=(-P(i,j));
        B(h*sz+i, h*sz+j)=P(i,j);
      }
    }
  }
  //Setter inn R
  for(int h=0; h<(sz-1);h++){
    for(int i=0; i<sz;i++){
      for(int j=0; j<sz;j++){
        A((h+1)*sz+i,h*sz+j)=(-R(i,j));
        A(h*sz+i, (h+1)*sz+j)=(-R(i,j));
        B((h+1)*sz+i,h*sz+j)=R(i,j);
        B(h*sz+i, (h+1)*sz+j)=R(i,j);
      }
    }
  }
  //Setter inn diagonalene i A og B
  for(int i=0; i<sz2; i++){
    A(i,i)=a(i);
    B(i,i)=b(i);
  }
}
//Finner b-en fra problem 3
arma::cx_colvec findb(arma::sp_cx_mat B, arma::cx_vec u){
  int lu=u.n_elem;
  arma::cx_colvec u_n=B*u;
  return u_n;
}
//Finner u(n+1)
arma::cx_vec findu_new(arma::sp_cx_mat A, arma::cx_colvec b){
  arma::cx_vec u_new=arma::spsolve(A,b);
  return u_new;
}
//Ble ubrukt til slutt, men skulle hvor endene av veggene lå
arma::vec findWall(int sl){
  arma::vec wall=arma::vec(sl*2).fill(0.);
  double endwalls=(1-(sl-1)*0.05)/2;
  wall(0)=endwalls;
  double next=endwalls;
  for(int j=1;j<(sl*2);j++){
    next+=0.05;
    wall(j)=next;
  }
  return wall;
}
//Lager veggen med potensialet.
arma::vec makeV(int sz, int sl, arma::vec sln, double v0){
  arma::vec wally=sln;
  std::cout << "wally" <<wally<< std::endl;
  double VStor=v0;
  double wallxstart=0.5-0.02/2;
  int wxs=int(std::round(wallxstart*sz));
  double wallxend=0.5-0.02/2;
  int wxe=int(std::round(wallxstart*sz));
  arma::mat Vmat=arma::mat(sz, sz).fill(0.);
  int o=1;
  for(int a=0;a<(wally.n_elem-1);a++){
    int wallys=int(std::round(wally(a)*sz));
    int wallye=int(std::round(wally(a+1)*sz));
    if(o>0){
      for(int i=wxs;i<=wxe;i++){
        for(int j=wallys; j<wallye; j++){
          Vmat(i,j)=VStor;
        }
      }
    }
    o=(o*(-1));
  }
  //Gjør den om til en vektor som u.
  arma::vec Vvec=arma::vec(sz*sz).fill(0.);
  for(int i=0;i<sz;i++){
    for(int j=0; j<sz;j++){
      int k=FindK(i,j,sz);
      Vvec(k)=Vmat(i,j);
    }
  }
  return Vvec;
}
//Finner sannsynligheten for å finne partikkelen inni systemet som burde være nærme 1
double FindP(arma::cx_vec u_in){
  arma::vec P=arma::real(u_in)%arma::real(u_in) + arma::imag(u_in)%arma::imag(u_in);
  double p=arma::accu(P);
  return p;
}
//Konverterer en kompleks vektor av størrelse k tilbake til en M-2xM-2 matrise
arma::cx_mat BackToMat(arma::cx_vec u){
  int sz2=u.n_elem;
  int sz=std::sqrt(sz2);
  arma::cx_mat U=arma::cx_mat(sz, sz).fill(0.);
  for(int i=0;i<sz;i++){
    for(int j=0;j<sz;j++){
      int k=FindK(i,j,sz);
      U(i,j)=u(k);
    }
  }
  return U;
}
//Konverterer en reell vektor fra vektor tilbake til en M-2xM-2 matrise
arma::mat BackToRealMat(arma::vec u){
  int sz2=u.n_elem;
  int sz=std::sqrt(sz2);
  arma::mat U=arma::mat(sz, sz).fill(0.);
  for(int i=0;i<sz;i++){
    for(int j=0;j<sz;j++){
      int k=FindK(i,j,sz);
      U(i,j)=u(k);
    }
  }
  return U;
}
