#include <iostream>
#include <string>
#include <vector>
using namespace std;    

class Solution {
    public:

    int isSubsequence(string s, string t){
        int i = 0;
        int j = 0;
        
        while(j < t.length() && i < s.length()){
            if(t[j] == s[i]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i == s.length();
    }
};

int main() {
    Solution obj;

    string  s = "abc";
    string  t = "axgbdc";

    cout << obj.isSubsequence(s,t);
}