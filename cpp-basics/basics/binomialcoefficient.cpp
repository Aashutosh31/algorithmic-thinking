#include <iostream>
using namespace std;

// Long code with redundancy
/*
int nfactorial(int n) {
    int nfactorial = 1;
    for(int i = 1; i <= n ; i++){
        nfactorial *= i;
    }
    return nfactorial;
}

int rfactorial(int r) {
    int rfactorial = 1; 
    for(int i = 1; i <= r ; i++){
        rfactorial *= i;
    }
    return rfactorial;
}

int nsubrfactorial (int n,int r) {
    int nsubr  = n - r;
    int nsubrfactorial = 1;
      for(int i = 1; i <= nsubr ; i++){
        nsubrfactorial *= i;
    }
    return nsubrfactorial;
}

int main () {
    int nfac = nfactorial(4);
    int rfac = rfactorial(2);
    int nsubr = nsubrfactorial(4,2);

    int ncr =  nfac / (rfac * nsubr); 
    cout<< "4C2 = " << ncr ;
}
*/
//Short and effecient code 

int factorial ( int x ){
    int result =  1;
    for(int i = 1; i <= x; i++){
        result *= i;
    }
    return result;
}

int main () {
    int n = 4;
    int r = 2;

    int ncr = factorial(n)/(factorial(r) * factorial(n-r));
    cout<< "4C2 = " << ncr ;

}