# 🧠 DSA Log — Jump Game II (LeetCode 45)

## 📅 Date
2026-05-05

---

## 🚀 Problem
**Jump Game II**
You are given a 0-indexed array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.
Each element `nums[i]` represents the maximum length of a forward jump from index `i`.
Return the **minimum** number of jumps required to reach the last index. (It is guaranteed that you can reach the last index).

---

## 🎯 Approach
### Idea
Use **Greedy / Implicit Breadth-First Search (BFS)**:
* In Jump Game I, we only cared *if* we could reach the end, so we constantly tracked our absolute maximum reach.
* Here, we need the *minimum jumps*. We cannot just jump blindly to the biggest number. We must evaluate a "Zone" (or level) of options, find the absolute best launchpad within that zone, and only officially record a jump when we reach the absolute boundary of our current zone.
* We use a "Trigger Line" (`currentEnd`) to tell the computer exactly when to count a jump.

---

## 💡 Logic
1.  Initialize three variables: `farthest = 0`, `currentEnd = 0`, `jumps = 0`.
2.  Iterate through the array. **Crucial:** Stop at `n - 1` (`i < nums.size() - 1`). If we reach the last index, we don't need to jump again.
3.  **Continuous Tracking:** On every single loop, update `farthest = max(farthest, i + nums[i])`. This is our scout looking ahead.
4.  **The Trigger Line:** Check `if (i == currentEnd)`.
    * If our pointer `i` hits the boundary of our current zone, we have officially evaluated all our options for this jump.
    * *Action:* Increment `jumps++`.
    * *Action:* Draw a new trigger line at the absolute furthest point we discovered (`currentEnd = farthest`).

---

## 💻 Code
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;   // The absolute furthest index we can see
        int currentEnd = 0; // The trigger line for counting a jump
        int jumps = 0;      // Total jumps taken

        // Stop checking right before the last index
        for(int i = 0; i < nums.size() - 1; i++){
            
            // 1. Constantly scout the furthest possible reach
            farthest = max(farthest, i + nums[i]);
            
            // 2. Did we hit the boundary of our current options?
            if(i == currentEnd){
                jumps++;                 // Officially take the jump
                currentEnd = farthest;   // Extend the boundary to the new limit
            }
        }
        return jumps;
    }
};
```

---

## 🐞 Mistakes I Made
### 1. The Accumulation Bug (`+=`) ❌
```cpp
maxReach += j + nums[j];
```
👉 Attempted to add the new jump calculation to the old jump calculation. This resulted in teleporting past the array bounds.
👉 *Correction:* Array indices are absolute coordinates, not distances. Always use `max()` to find the absolute highest index, never `+=`.

### 2. The Double-Duty Variable ❌
👉 Tried to use the loop index pointer (`j`) as both the array index *and* the total jump count. 
👉 *Correction:* Looking at an option does not equal taking a jump. You must use a dedicated `jumps` counter that only increments under a specific condition.

### 3. Missing the Trigger Line ❌
👉 Attempted to solve it like Jump Game I, without realizing the computer needs a physical boundary (`currentEnd`) to know when a "level" of choices has been fully evaluated. 

---

## 💡 Key Learnings
* **Implicit BFS:** Whenever a problem asks for the "minimum steps/jumps" in an array or grid, it is almost always Breadth-First Search. The `currentEnd` variable is simply acting as the boundary of a BFS "level."
* **Loop Bounds:** In jump tracking, never let the loop process the final destination index. If you are standing on the finish line, you don't calculate another jump.

---

## 🔁 Pattern Identified
**Type:** Greedy / Implicit BFS
Used in:
* Jump Game II
* Minimum operations to reach a target.

---

## ⏱️ Complexity
* **Time:** $O(N)$. We iterate through the array exactly once.
* **Space:** $O(1)$. We track states using only three integer variables.

---

## 🏁 Final Takeaway
> To find the minimum jumps, explore your entire current zone before committing. Use a trigger line to know when to jump.

