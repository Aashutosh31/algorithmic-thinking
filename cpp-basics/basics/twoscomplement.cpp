#include <iostream>
using namespace std;

int binarytodecimal(int num, int base) {
    int result = 0; int pow = 1;
    while (num > 0) {
        int lastdigit = num % 10;
        lastdigit *= pow;
        result += lastdigit;
        pow *= base;
        num = num/10;
    }
    return result;
}
int decimaltobinary(int num , int base) {
    int ans = 0; int pow = 1;
    while (num > 0 ){
        int rem = num % base;
        num = num / base;

        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
}


int onescomplement(int num){
    int ans = 0;  int pow = 1;

    while (num > 0) {
        int rem = num % 10;
        

        if ( rem == 0){
            rem = 1;
        }else{
            rem = 0;
        }

        ans += (rem * pow);
        pow *= 10;
        num = num / 10;
    }
    return ans;
}

int twoscomplement(int num){
    int one = onescomplement(num);
   int result = 0; int carry = 1; int pow = 1;

   while (one > 0 || carry > 0){
    int digit = one % 10;
    int sum = digit + carry;

    result += (sum % 2) * pow;
    carry = sum/2;

    pow *= 10;
    one /= 10;
   }
   return result;
}


int main () {
    int num = decimaltobinary(8,2);
    cout << num << endl;
    cout << onescomplement(num) << endl;
    cout << twoscomplement(num);
}