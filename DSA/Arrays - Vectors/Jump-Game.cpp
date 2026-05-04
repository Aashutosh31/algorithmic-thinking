#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    bool canJump(vector<int>& nums){
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > maxReach){
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2,3,1,1,4};

    cout<<obj.canJump(nums);
}