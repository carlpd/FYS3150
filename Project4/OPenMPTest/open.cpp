int power(int x);

#include <omp.h>
#include <iostream>
#include <time.h>

main(){
  int sum = 0;
  /* start parallel region */

  clock_t t1 = clock();
  for (float i=0.; i<100000;){
    sum = sum + power(i);
    i = i + 0.2123;
  }
  clock_t t2 = clock();
  double ds = ((double) (t2-t1)) / CLOCKS_PER_SEC;

  std::cout << sum;
  std::cout << std::endl;
  std::cout << ds;
  std::cout << std::endl;
  sum = 0;

  #pragma omp parallel shared(sum)



  {
      #pragma omp for
      t1 = clock();
      for (float i=0.; i<100000;){
        sum = sum + power(i);
        i = i + 0.0123;
      }
      t2 = clock();
  }


  ds = ((double) (t2-t1)) / CLOCKS_PER_SEC;
  std::cout << sum;
  std::cout << std::endl;
  std::cout << ds;
  std::cout << std::endl;
}

int power(int x){
  return x*x;
}
