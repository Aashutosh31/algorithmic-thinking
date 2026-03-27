#include <iostream>
using namespace std;

int binarytodecimal(int num, int base){
    int pow = 1;
    int result = 0;
 while (num > 0 ){
    int lastdigit = num % 10;
    lastdigit *= pow ;
    result += lastdigit;
    pow *= base;
    num = num /10;
 }
 return result;
}

int decimaltobase(int result , int base ){
    int ans = 0; int pow = 1;
    while( result > 0 ) {
        int rem = result % base;
        result = result / base ;

        ans += (rem * pow);
        pow *= 10;
    }
    return ans;
}


int main () {
    cout << binarytodecimal(0010001,2) << endl;
    int result = binarytodecimal(0010001,2);
    cout << decimaltobase(result , 8);
}