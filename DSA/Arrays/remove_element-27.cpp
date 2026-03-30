#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//// return number of elements NOT equal to val (k)
int removeElement (vector<int> & nums, int val) {
    int k = 0;

    for (int i=0; i<nums.size(); i++){
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
};

int main () {
    Solution obj;
    vector<int> nums = {3,2,3,2};
    int val = 2;

    int result = obj.removeElement(nums,val);
    cout << "Array after operation: ";
    for(int i = 0; i < result; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Result: " << result << endl;

    return 0;
}