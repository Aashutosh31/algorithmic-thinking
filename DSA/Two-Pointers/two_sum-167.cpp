#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> twosum(vector<int>&numbers,int target){
        int index1 = 0;
        int index2 = numbers.size() - 1;

        while(index1 < index2){
            if(numbers[index1] + numbers[index2] < target){
                index1++;
            }else if (numbers[index1] + numbers[index2] > target){
                index2--;
            }else if (numbers[index1] + numbers[index2] == target){
                return {index1 + 1, index2 + 1};
            };
        };
         return {index1 + 1, index2 + 1};
    };
};

int main () {
        Solution obj;

        vector<int> numbers = {2,7,11,15};
        int target = 9;

        vector<int> result  =  obj.twosum(numbers,target);
         for(int i = 0; i < result.size(); i++){
               cout << result[i] << " ";
         }
    }