#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

      int removeDuplicates(vector<int>& nums){
        int a = 0;
        int count = 1;

        for(int b = 1; b < nums.size(); b++){
            if(nums[a] != nums[b]){
                a++;
                nums[a] = nums[b];
                count++;
            }
        }
        return count;
    }
};

    int main() {
        Solution  obj;

        vector<int> nums = {1,1,1,2,2,3};

        int result = obj.removeDuplicates(nums);
        for ( int i=0; i < result ; i++){
            cout<<nums[i];
        }
    };
