#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void rotateArray(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            ans[(i+k)%n] = nums[i];
        }
        for(int j=0; j<n; j++){
            nums[j] = ans[j];
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums={1,2,3,4,5,6};
    int k = 3;


    obj.rotateArray(nums,k);
    for(int num : nums){
        cout<< num << " ";
    }
}