#include <iostream>
using namespace std;

class Solution{
    public:
    
    int translator(char c){
        switch(c){
         case 'I': return 1;
         case 'V': return 5;
         case 'X': return 10;
         case 'L': return 50;
         case 'C': return 100;
         case 'D': return 500;
         case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s){
        int number = 0;
        
        for(int i = 0; i < s.length()-1; i++){
            int current = translator(s[i]);
            int next = translator(s[i + 1]);

            if(current < next){
                number -= current;
            }else {
                number += current;
            }
        }
        int LastDigitValue = translator(s[s.length() - 1]);
        number += LastDigitValue;
        return number;
    }
};

int main() {
    Solution obj;
    string s = "MCMXCIV";

    cout << obj.romanToInt(s);
    return 0;
}