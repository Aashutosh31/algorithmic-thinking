# 🧠 DSA Log — Majority Element (LeetCode 169)

## 📅 Date
2026-04-22

---

## 🚀 Problem
**Majority Element**
Given an array `nums` of size `n`, return the majority element.
The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

---

## 🎯 Approach
### Idea
Use the **Boyer-Moore Voting Algorithm** ("King of the Hill").
* Since the majority element appears more than 50% of the time, it will always survive a 1-on-1 battle against every other different element in the array.
* We keep track of a `candidate` and a `count`. 
* If the count drops to 0, the current number becomes the new candidate.
* If the next number matches the candidate, count goes up. If it differs, count goes down.

---

## 💡 Logic
1. Initialize `candidate = 0` and `count = 0`.
2. Loop through every number in the array:
   * **Rule 1 (New Candidate):** If `count == 0`, set `candidate = current number` AND set `count = 1`.
   * **Rule 2 (Match):** Else if `candidate == current number`, increment `count++`.
   * **Rule 3 (Mismatch):** Else, decrement `count--`.
3. Return the `candidate`.

---

## 💻 Code
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
                count = 1; // Initialize the count for the new candidate
            }else if(candidate == nums[i]){
                count++;
            }else {
                count--;
            }
        }
        return candidate;
    }
};
```

---

## 🐞 Mistakes I Made
### 1. Value vs. Frequency Confusion ❌
👉 Initially tried to compare the *value* of the current index against the *value* of the middle index (`nums[b] >= nums[n / 2]`). This ignores the frequency requirement entirely. 

### 2. State Overwrite (Missing Initialization) ❌
```cpp
if(count == 0){
    candidate = nums[i];
    // Forgot count = 1;
}
```
👉 When assigning a new candidate, I forgot to give them a starting count of 1. This caused `count` to permanently stay at 0, resulting in the code always returning the very last element in the array, regardless of majority.

---

## 💡 Key Learnings
* **LeetCode Tags Lie:** An "Easy" problem that requires a specific, named math algorithm (like Boyer-Moore) is not actually easy. Don't beat yourself up over it.
* **State Management:** Always ensure that when a state changes (like a new candidate taking over), all associated variables (like their count/health) are updated simultaneously.

---

## 🔁 Pattern Identified
**Type:** Boyer-Moore Voting Algorithm / Counting
Used in:
* Majority Element
* Finding elements that appear $> N/K$ times in an array.

---

## ⏱️ Complexity
* **Time:** $O(n)$. Single pass through the array.
* **Space:** $O(1)$. Only using two integer variables.