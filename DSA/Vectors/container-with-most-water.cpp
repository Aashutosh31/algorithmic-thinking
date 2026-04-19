#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public: 
 int maxArea(vector<int>& height){
    int left = 0;
    int right = height.size() - 1;
    int area = 0;

    while(left < right){
        int newArea = (right - left ) * min(height[left],height[right]);

        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }

        if(newArea > area){
            area = newArea;
        }
    }
    return area;
 }
};

int main() {
    Solution obj;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = obj.maxArea(height);
    for(int i = 0; i < height.size(); i++){
        cout << height[i] << " ";
    }    cout << endl;
    cout << "Max Area: " << result << endl;
    return 0;
}