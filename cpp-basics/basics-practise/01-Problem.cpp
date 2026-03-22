#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter a number: ";
    cin >> n1;
    cout << "Enter another number: ";
    cin >> n2;
    
    int sum  = n1 + n2;
    int diff = n1 - n2;
    int prod = n1 * n2;
    int div = n1/n2;

    cout << "Sum: " << sum ;
    cout << "\nDifference: " << diff;
    cout << "\nProduct: " << prod;
    cout << "\nDivision: " << div;
}