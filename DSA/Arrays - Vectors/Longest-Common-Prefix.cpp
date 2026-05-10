#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:

     string longestPrefix(vector<string>& strs){
        for(int j = 0; j < strs[0].length(); j++){
            for(int i = 1; i < strs.size(); i++){
                if(j == strs[i].length() || strs[i][j] != strs[0][j]){
                    return strs[0].substr(0,j);
                }
            }
        }
        return strs[0];
     }
};

int main() {
    Solution obj;
    vector<string> strs = {"flower","flok","flask"};

    cout<<obj.longestPrefix(strs);
}