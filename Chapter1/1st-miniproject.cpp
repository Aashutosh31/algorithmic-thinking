#include <iostream>
using namespace std;

int main() {
    string name;
    float m1, m2, m3;

    cout<<"Enter Your Name:";
    getline(cin, name);
    cout<<"Enter Marks in Subject 1:";
    cin>>m1;
    cout<<"Enter Marks in Subject 2:";
    cin>>m2;
    cout<<"Enter Marks in Subject 3:";
    cin>>m3;

    float total = m1 + m2 + m3;
    float percentage = (total/300) * 100;

    cout <<"\n----- Report Card ------\n";
    cout << "Name: "<<name<<"\n";
    cout << "Total Marks: "<<total<<"\n";
    cout << "Percentage: "<<percentage<<"%\n";

    if(percentage >= 90) cout << "Grade: A+";
    else if(percentage >= 80) cout << "Grade: A";
    else if(percentage >= 70) cout << "Grade: B+";
    else if(percentage >= 60) cout << "Grade: B";
    else if(percentage >= 50) cout << "Grade: C";
    else if(percentage >= 40) cout << "Grade: D";
    else cout << "Grade: F";
}