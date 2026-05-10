#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

    int lengthOfLastWord(string s) {
        int word = 0;
        for(int i = s.length() - 1; i >= 0; i--){  
        if(s[i] != ' ') {
            word++;
        }
        else if(s[i] == ' ' && word != 0 ){
            break;
        }
    }
        return word;
    }
};

int main() {
   Solution obj;
   string s = " a whale is swimming  ";
   cout<<obj.lengthOfLastWord(s);
}