#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int minJump(vector<int>& nums){
        int farthest = 0;
        int currentEnd = 0;
        int jumps = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);

            if(i == currentEnd){
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2,3,1,1,4};

    cout<<obj.minJump(nums);
}