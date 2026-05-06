#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int hIndex(vector<int>& repos){
        sort(repos.rbegin(),repos.rend());
        int h = 0;
        for(int i = 0; i < repos.size(); i++){
            if(repos[i] > h){
                h++;
            }
        }
        return h;
    }
};

int main() {
    Solution obj;
    vector<int> repos = {6,6,6,6,6,};

    cout<<obj.hIndex(repos);

}