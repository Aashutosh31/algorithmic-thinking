#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter a number: ";
    cin >> n1;
    cout << "Enter another number: ";
    cin >> n2;

    n1 = n1 + n2;
    n2 = n1 - n2;
    n1 = n1 - n2;

    cout << "After Swapping \n";
    cout << "First Number = " << n1;
    cout << "\nSecond Number = " << n2;
}