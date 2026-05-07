#include <iostream>
#include <string>
#include <vector>
using namespace std;    

class Solution {
    public:

    int strStr(string haystack, string needle){
        int hlen = haystack.length();
        int nlen = needle.length();
        int j = 0;

        for(int i = 0; i <= hlen - nlen; i++){
            for( j = 0; j < nlen; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == nlen) return i;
        }
        return -1;
    }
};

int main() {
    Solution obj;

    string  haystack = "aaaa";
    string  needle = "aab";
    
    cout << obj.strStr(haystack,needle);
    
}