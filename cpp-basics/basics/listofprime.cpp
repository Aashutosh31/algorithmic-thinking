#include <iostream>
using namespace std;

bool primeCheck(int n) {
    if(n <= 1) return false;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void printPrime(int n) {
    for (int i = 1 ; i <= n ; i++){
        if(primeCheck(i)){
           cout << i << endl;
        }
    }
}

int main () {
    printPrime(5);
}