#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int buy = 0;
        int sell = 0;

        while(sell < prices.size()){
            int profit = prices[sell] - prices[buy];

            if(profit <= 0){
                buy = sell;
                sell++;
            }else{
                buy++;
                sell++;
            }
            if(profit > 0) {
                maxprofit += profit;
            }
        }
        return maxprofit;
}
};

int main() {
    Solution obj;
    vector<int> prices = {7,1,5,3,6,4};

    cout <<obj.maxProfit(prices);
}