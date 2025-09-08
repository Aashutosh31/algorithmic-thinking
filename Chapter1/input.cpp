#include <iostream>
using namespace std;

int main() {
    string name; // Declare a string variable to hold the user's name
    int age; // Declare an integer variable to hold the user's age

    cout << "Enter your name: "; // Prompt the user for their name
    getline(cin, name); // Read the entire line of input for the name

    cout << "Enter your age: "; // Prompt the user for their age
    cin >> age; // Read the integer input for the age

    cout << "Hello, " <<name<<"! You are "<<age<<"years old.";
}