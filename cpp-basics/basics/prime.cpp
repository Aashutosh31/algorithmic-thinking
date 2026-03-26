#include <iostream>
using namespace std;

//To Check if number is prime or not 
//1.The number n should be greater than 1 and it should not have remainder 0 when divided by any number i other than itself or 1 .
//2. n % i != 0

int primeCheck(int n) {
    if (n <= 1 ) return false;

    for (int i = 2 ; i < n; i++) {
        if (n % i == 0){
            return false ;
        }
    }  
    return true;
}

int main () {
    if (primeCheck(9)){
        cout << "prime"<< endl;
    }else {
        cout<< "Not Prime";
    }
}