#include <iostream>
using namespace std;

void decimaltobinary(int num, int base) {
     while(num  >=  1) {
         cout << num % base << endl;
         num  = num / base;
     }
}


int main () {
     decimaltobinary(4,2);
}