#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {4,5,6};

    int m = 3;  
    int n = nums2.size();

    obj.merge(nums1, m, nums2, n);

    // print result
    for(int num : nums1){
        cout << num << " ";
    }
}