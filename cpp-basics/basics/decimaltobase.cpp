#include <iostream>
using namespace std;

// Correct logic, works for any base, but prints in reverse order
void decimaltob(int num, int base) {
     while(num  >=  1) {
         cout << num % base << endl;
         num  = num / base;
     }
}


// Prints in correct order but only reliable for base <= 10
int decimaltobase(int num, int base){
    int ans = 0 ; int pow = 1;
    while(num > 0){
      int  rem = num % base;
      num = num / base;

      ans += (rem * pow);
      pow *= 10 ;
    }
    return ans;
}



int main () {
     decimaltob(44,8);
     cout << decimaltobase(44,8);
}

