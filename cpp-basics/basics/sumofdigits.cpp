#include <iostream>
using namespace std;

//sum of digits of a number 
// 1. Take num % 10 for remainder i.e lastdigit. 
// 2. Now to get remaining digits num/10.

int digitAdd(int num){
   int digitsum = 0;
   while(num > 0 ){
   int lastdigit = num % 10;
    num = num/10;
    digitsum += lastdigit;
   }
   return digitsum;
}

int main () {
    cout << digitAdd(1234) << endl;
}