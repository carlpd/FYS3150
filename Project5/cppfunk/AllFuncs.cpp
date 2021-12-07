#include "../hpp/AllFunks.hpp"
//Liten greie for å finne k ene i u-vektoren
int FindK(int i, int j, int sz){
  int k =  i + j*sz;
  return k;
}
//Lager et gaussisk element
arma::cx_double makegaus(arma::cx_double x, double sig, double mu, double kx){
  arma::cx_double i=arma::cx_double(0,1);
  arma::cx_double xmu=x-mu;
  return exp((-1.)*xmu*xmu/(sig*sig*2))*exp(i*kx*(xmu));
}
//Setter sammen en gaussisk initialtilstand, ikke ferdig, sz er størrelsen(size) av u, altså M-2
arma::cx_vec makeinit(int sz, double sigx, double sigy, double mux, double muy, double kx, double ky){
  int sz2=sz*sz;
  arma::cx_vec u_in=arma::cx_vec(sz2).fill(0.);
  arma::vec xy=arma::linspace(0,1,sz);
  for(int i=0; i<sz; i++){
    arma::cx_double fx=makegaus(xy(i), sigx, mux, kx);
    for(int j=0; j<sz; j++){
      arma::cx_double fy=makegaus(xy(j), sigy, muy, ky);
      int k=FindK(i,j, sz);
      u_in(k)=fx*fy;
    }
  }
  arma::vec absu=arma::abs(u_in);
  double usum=arma::sum(absu);
  arma::cx_double p = arma::cdot(u_in, u_in);
  arma::cx_vec unorm=u_in/std::sqrt(p);
  return unorm;
}

arma::cx_vec makea(int sz, arma::vec v, arma::cx_double r, double dt){
  int sz2=sz*sz;
  arma::cx_vec a=arma::cx_vec(sz2).fill(0.);
  for(int i=0; i<sz; i++){
    for(int j=0;j<sz; j++){
      int k =FindK(i, j, sz);
      a(k)=1.+(4.+0i) * r+ i * dt * v(k)/2;
    }
  }
  return a;
}
arma::cx_vec makeb(int sz, arma::vec v, arma::cx_double r, double dt){
  int sz2=sz*sz;
  arma::cx_vec b=arma::cx_vec(sz2).fill(0.);
  for(int i=0; i<sz; i++){
    for(int j=0;j<sz; j++){
      int k =FindK(i, j, sz);
      b(k)=1.-(4.+0i)*r-i*dt*v(k)/2;
    }
  }
  return b;
}
//Lager A og B
void MakeAB(arma::sp_cx_mat& A,  arma::sp_cx_mat& B, arma::cx_vec a, arma::cx_vec b, arma::cx_double r){
  int sz2=a.n_elem;
  int sz=sqrt(sz2);
  arma::cx_mat R=arma::cx_mat(sz, sz).fill(0.);
  for(int j=0; j<sz; j++){
    R(j,j)=r;
  }
  //std::cout<<"Lagde R"<<std::endl;
  //std::cout<<R<<std::endl;
  arma::cx_mat P=arma::cx_mat(sz, sz).fill(0.);
  for(int j=0; j<(sz-1);j++){
    //std::cout<<"P"<<P(j+1,j)<<std::endl;
    P(j+1,j)=r;
    P(j,j+1)=r;
  }
  //std::cout<<"Lagde P"<<std::endl;
  //std::cout<<P<<std::endl;
  for(int h=0; h<sz;h++){
    for(int i=0; i<sz;i++){
      for(int j=0; j<sz;j++){
        A(h*sz+i, h*sz+j)=(-P(i,j));
        B(h*sz+i, h*sz+j)=P(i,j);
      }
    }
  }
  //std::cout<<"Satte inn R"<<std::endl;
  //std::cout<<A<<std::endl;
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
  //std::cout<<"Satte inn P"<<std::endl;
  //std::cout<<A<<std::endl;
  for(int i=0; i<sz2; i++){
    A(i,i)=a(i);
    B(i,i)=b(i);
  }
}
//Finner b-en fra problem 3
arma::cx_vec findb(arma::sp_cx_mat B, arma::cx_vec u){
  int lu=u.n_elem;
  arma::cx_vec u_n=B*u;
  return u_n;
}
//Finner u(n+1)
arma::cx_vec findu_new(arma::sp_cx_mat A, arma::cx_vec b){
  arma::cx_vec u_new=arma::spsolve(A,b);
  return u_new;
}
arma::vec findWall(int sl){
  //std::cout<<"Lager veggen"<<std::endl;
  //std::cout << sl << std::endl;
  arma::vec wall=arma::vec(sl*2).fill(0.);
  double endwalls=(1-(sl-1)*0.05)/2;
  wall(0)=endwalls;
  double next=endwalls;
  for(int j=1;j<(sl*2);j++){
    next+=0.05;
    wall(j)=next;
  }
  //std::cout<<"wall"<<wall<<std::endl;
  return wall;
}
arma::vec makeV(int sz, int sl){
  arma::vec wally=findWall(sl);
  std::cout << "wally" <<wally<< std::endl;
  double VStor=std::pow(10,10);
  double wallxstart=0.5-0.02/2;
  int wxs=int(std::round(wallxstart*sz));
  double wallxend=0.5-0.02/2;
  int wxe=int(std::round(wallxstart*sz));
  arma::mat Vmat=arma::mat(sz, sz).fill(0.);
  int o=1;
  int wallys=0;
  for(int a=0;a<wally.n_elem;a++){
    std::cout<<"o"<<o<<std::endl;
    int wallye=int(std::round(wally(a)*sz));
    std::cout<<"wallys1"<<wallys<<std::endl;
    std::cout<<"wallyse"<<wallye<<std::endl;
    if(o>0){
      for(int i=wxs;i<=wxe;i++){
        for(int j=wallys; j<=wallye; j++){
          //std::cout << "makeVn" << std::endl;
          Vmat(i,j)=VStor;
        }
      }
    }

    wallys=int(std::round(wally(a)*sz));
    //std::cout<<"wallys"<<wallys<<std::endl;
    o=(o*(-1));
  }
  int wallye=sz-1;
  for(int i=wxs;i<=wxe;i++){
    for(int j=wallys; j<=wallye; j++){
      //std::cout << "makeVn" << std::endl;
      Vmat(i,j)=VStor;
    }
  }
  arma::vec Vvec=arma::vec(sz*sz).fill(0.);
  //std::cout << "makeV2" << std::endl;
  for(int i=0;i<sz;i++){
    for(int j=0; j<sz;j++){
      int k=FindK(i,j,sz);
      Vvec(k)=Vmat(i,j);
    }
  }
  return Vvec;
}
//Konverterer en vektor av størrelse k tilbake til en ixj matrise
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
