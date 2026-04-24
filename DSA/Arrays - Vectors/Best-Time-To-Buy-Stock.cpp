#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int buy = 0;
        int sell = 1;
        int maxProfit = 0;

        while(buy < n && sell < n){
            int profit = prices[sell]-prices[buy];

            if(prices[sell] <= prices[buy]){
                buy = sell;
                sell++;
            }else{
                sell++;
            }

            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution obj;

    vector<int> prices = {2,1,4};
    
    cout<<obj.maxProfit(prices);
}