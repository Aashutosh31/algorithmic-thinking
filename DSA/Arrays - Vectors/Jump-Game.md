# 🧠 DSA Log — Jump Game (LeetCode 55)

## 📅 Date
2026-05-04

---

## 🚀 Problem
**Jump Game**
You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your **maximum** jump length at that position.
Return `true` if you can reach the last index, or `false` otherwise.

---

## 🎯 Approach
### Idea
Use a **Greedy Algorithm (Maximum Reach Tracker)**:
* Zeroes are the only threat in this problem, but actively searching for zeroes is a trap because you can often jump over them.
* Instead of looking at individual jumps, track your overall **momentum**. 
* Think of the numbers as gallons of gas. At every step, check: "Based on the gas I found in the past, what is the absolute furthest mile marker I can reach?"

---

## 💡 Logic
1.  Initialize a variable `maxreach = 0` to track the furthest index you can possibly reach.
2.  Iterate through the array one index at a time (`i`).
3.  **The Dead End Check:** If your current index `i` is greater than `maxreach`, it means you walked into a zone that your past jumps couldn't reach. You ran out of gas. Return `false`.
4.  **Update Momentum:** If you survived the dead end check, calculate the new reach from your current spot (`i + nums[i]`). Update `maxreach` if this new reach is further than your current `maxreach`.
5.  If the loop finishes without hitting a dead end, it means you successfully bridged every gap. Return `true`.

---

## 💻 Code
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;
        
        for(int i = 0; i < nums.size(); i++){
            // 1. Am I standing on an index that is mathematically impossible to reach?
            if(i > maxreach){
                return false; 
            }
            
            // 2. Can the jump from my current spot push my momentum even further?
            maxreach = max(maxreach, i + nums[i]);
        }
        
        return true;
    }
};
```

---

## 🐞 Mistakes I Made
### 1. The "Jump Over" Trap (Panic on Zero) ❌
```cpp
if(nums[i] == 0 && i != n) { return false; }
```
👉 If my code saw a `0`, it instantly returned `false`. This failed on `[2, 0, 2]` because it didn't realize the `2` at index 0 gave me enough momentum to completely fly over the `0`. 
👉 *Correction:* Don't panic at zeroes. Let the `maxreach` variable decide if a zero is actually a dead end.

### 2. The Forced Maximum Jump ❌
```cpp
i += nums[i]; 
```
👉 Attempted to traverse the array by physically jumping the `i` pointer by the maximum amount allowed. 
👉 The problem states `nums[i]` is the *maximum* jump, not the *required* jump. Sometimes a shorter jump lands you on a better number. Furthermore, if `nums[i]` is 0, `i += 0` causes an infinite loop. 
👉 *Correction:* Always iterate by `i++` to evaluate every single spot, and let `maxreach` handle the jump math.

---

## 💡 Key Learnings
* **Greedy State Tracking:** Some problems shouldn't be solved by moving pointers around physically. Instead, just walk forward normally (`i++`) and maintain a "state" variable (like `maxreach`) that calculates the physics in the background.

---

## 🔁 Pattern Identified
**Type:** Greedy Algorithm
Used in:
* Jump Game I & II
* Any array problem evaluating "reach," "coverage," or overlapping intervals.

---

## ⏱️ Complexity
* **Time:** $O(N)$. We iterate through the array exactly once.
* **Space:** $O(1)$. We only allocate one integer (`maxreach`).

---

## 🏁 Final Takeaway
> Don't fear the zero. Just track your momentum. 

