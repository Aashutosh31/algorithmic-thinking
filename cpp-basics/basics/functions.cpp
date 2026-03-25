#include <iostream>
#include <algorithm>
using namespace std;

//min of 2 
/*
//min of 2 

int printMin(int a , int b) {
        return min(a,b);
    }


int main () {
    cout << printMin(20,26) << endl;
    cout << printMin(24,12);
}
*/

//sum 1 to n 
int sum(int n ){
 int total = 0;
 for (int i = 1 ; i <= n ; i++){
    total += i ;

 }   
  return total;
}

// O(1) complexity
int bigO1(int n){
    return n * (n+1)/2;
}

int main () {
    cout << bigO1(9) << endl;
    cout << sum(9);
}