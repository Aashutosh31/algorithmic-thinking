#include <iostream>
using namespace std;
 
int main() {
    int Temperature;
    cout << "Enter the temperature in Celsius: ";
    cin >> Temperature;

    int  fahrenheit = (Temperature* 9/5) + 32;
    cout << "Temperature in F is : "<<fahrenheit <<"F";

}