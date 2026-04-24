# 🧠 DSA Log — Best Time to Buy and Sell Stock (LeetCode 121)

## 📅 Date
2026-04-24

---

## 🚀 Problem
**Best Time to Buy and Sell Stock**
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.
Maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit, or 0 if no profit can be achieved.

---

## 🎯 Approach
### Idea
Use a **Sliding Window / Fast-Slow Pointers**:
* Time only moves forward. We cannot use Two-Pointers from opposite ends because we cannot move backwards from the future. 
* We use a `buy` pointer (slow) and a `sell` pointer (fast).
* The `sell` pointer scans forward day by day to check the profit.
* If we ever encounter a day where the price drops below our `buy` price, we immediately slide our `buy` pointer to that new day, because it represents a better starting point for any future sales.

---

## 💡 Logic
1.  Initialize `buy = 0` and `sell = 1`.
2.  Initialize `Mainprofit = 0`.
3.  Loop while `sell` is within the bounds of the array:
    * Calculate `profit = prices[sell] - prices[buy]`.
    * **Rule 1 (New Low):** If `profit <= 0` (meaning the sell price is cheaper than the buy price), update `buy = sell` to start tracking from this new low point.
    * Move the `sell` pointer forward to check the next day.
    * **Rule 2 (Record Profit):** If the calculated profit is greater than `Mainprofit`, update `Mainprofit`.
4.  Return `Mainprofit`.

---

## 💻 Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int buy = 0;
         int sell = 1;
         int Mainprofit = 0;

        while(buy < prices.size() && sell < prices.size() ){
            int profit = prices[sell] - prices[buy];
            
            // If we found a lower price, jump the buy pointer to this new low
            if(profit <= 0 ){
                buy = sell;
                sell++;
            }
            else{
                sell++;
            }

            // Update max profit seen so far
            if(profit > Mainprofit){
                Mainprofit = profit;
            }
        }

        return Mainprofit;
    }
};
```

---

## 🐞 Mistakes I Made
### 1. The Time Machine Bug ❌
```cpp
sort(prices.begin(), prices.end());
```
👉 Attempted to sort the array to easily find the lowest and highest numbers. In chronological problems (like stock prices, chat logs, server timestamps), sorting destroys the timeline. You cannot buy on Tuesday and sell on Monday.

### 2. Opposite Ends Two-Pointer ❌
👉 Attempted to put a pointer at the beginning and the end of the array and shrink inward. This violates the forward-moving constraint of time, resulting in discarding future peaks if the logic forces the end pointer to move backward.

### 3. The Panic Button (Early Return) ❌
👉 Used an `else { return 0; }` if the price dropped. This instantly killed the loop and prevented the code from seeing massive stock rallies later in the array. 

---

## 💡 Key Learnings
* **Chronological Arrays:** Never sort data that relies on a strict timeline.
* **Sliding Window Baseline:** When searching for a maximum difference, if you find a new absolute minimum, shift your baseline (left pointer) to that new minimum immediately. 

---

## 🔁 Pattern Identified
**Type:** Sliding Window / State Tracking
Used in:
* Best Time to Buy and Sell Stock
* Finding the maximum contiguous subarray (Kadane's Algorithm concept).

---

## ⏱️ Complexity
* **Time:** $O(N)$. The `sell` pointer iterates through the array exactly once.
* **Space:** $O(1)$. Constant extra space used for pointers and variables.