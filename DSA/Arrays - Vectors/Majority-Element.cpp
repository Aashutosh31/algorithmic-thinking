#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
    int majorityElement(vector<int>& nums){
        int candidate = 0;
        int count = 0;

        for(int i=0; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
                count++;
            }else if (candidate == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2,1,2,3,2,2,2};

    cout << obj.majorityElement(nums);
}