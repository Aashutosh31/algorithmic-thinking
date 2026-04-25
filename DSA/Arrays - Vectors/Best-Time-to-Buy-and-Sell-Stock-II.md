# 🧠 DSA Log — Best Time to Buy and Sell Stock II (LeetCode 122)

## 📅 Date
2026-04-25

---

## 🚀 Problem
**Best Time to Buy and Sell Stock II**
You are given an integer array `prices`. On each day, you may decide to buy and/or sell the stock. You can hold at most one share at a time, but you can sell and buy the stock multiple times on the same day. Find the maximum profit you can achieve.

---

## 🎯 Approach
### Idea
Use a **Greedy Algorithm (Adjacent Day Comparison)**:
* The rules allow infinite transactions. Therefore, we don't need to find one massive global dip and peak like in Stock I.
* We just need to capture every single upward movement on the chart.
* If tomorrow's price is higher than today's price, buy today and sell tomorrow. 

---

## 💡 Logic
1.  Iterate through the array starting from day 1 (index 1).
2.  Compare today's price (`prices[i]`) with yesterday's price (`prices[i-1]`).
3.  If today is higher, add the difference directly to `maxprofit`.
4.  Ignore any days where the price drops.

---

## 💻 Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        
        // Start at index 1 and just look backward one day at a time
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                maxprofit += prices[i] - prices[i-1];
            }
        }
        
        return maxprofit;
    }
};
```

---

## 🐞 Mistakes I Made
### 1. Pointer Desync (The Screenshot Bug) ❌
👉 In my initial code, the `else` block only incremented `sell++`. This anchored the `buy` pointer to an old price even after a profitable transaction, turning it back into a "Stock I" sliding window and generating incorrect phantom profits.
👉 *Correction*: By adding `buy++` to the else block (or just using `i` and `i-1`), I ensured the pointers were always exactly one day apart, successfully implementing the Greedy approach.

---

## 💡 Key Learnings
* **Infinite Transactions = Greedy:** Whenever a problem allows unlimited moves to maximize a sum, look for a greedy local strategy. Gathering every small adjacent profit is mathematically equal to (or better than) finding the absolute outer bounds.
* **Manual Dry Runs Work:** Stepping through the code manually revealed the exact logic flow and proved the fix worked before even hitting submit.

---

## 🔁 Pattern Identified
**Type:** Greedy Algorithm
Used in:
* Best Time to Buy and Sell Stock II
* Any array problem involving capturing all local maximums or positive slopes.

---

## ⏱️ Complexity
* **Time:** $O(N)$. We iterate through the array exactly once.
* **Space:** $O(1)$. We do not allocate any extra memory.

---

## 🏁 Final Takeaway
> If you can buy and sell infinitely, just farm the positive slopes.