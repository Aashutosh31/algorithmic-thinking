# 🧠 DSA Log — Rotate Array (LeetCode 189)

## 📅 Date
2026-04-23

---

## 🚀 Problem
**Rotate Array**
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

---

## 🎯 Approach
### Idea
Use an **Auxiliary Array (The "Waiting Room")**:
* If we try to move elements directly inside the original array, we will overwrite data before we have a chance to move it.
* To prevent this, we create a temporary `ans` array of the exact same size.
* We calculate the future index for every number using the modulo operator `%` (which handles wrap-around perfectly) and drop the number into the temporary array.
* Once the temporary array is fully built, we copy it back over the original array.

---

## 💡 Logic
1. Create a safe vector `ans` with `n` pre-allocated empty slots.
2. **Phase 1 (The Push):** Loop through the original `nums` array. 
   * Calculate the new index: `(i + k) % n`.
   * Push the data forward into the waiting room: `ans[(i + k) % n] = nums[i]`.
3. **Phase 2 (The Copy):** Use a completely separate loop to copy the finished `ans` array back into `nums`.

---

## 💻 Code
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        
        // Phase 1: Place all elements in their future positions in a safe array
        for(int i = n - 1; i >= 0; i--){
            ans[(i + k) % n] = nums[i];
        }
        
        // Phase 2: Copy the safe array back to the original
        for(int j = 0; j < n; j++){
            nums[j] = ans[j];
        }
    }
};
```

---

## 🐞 Mistakes I Made
### 1. In-Place Forward Overwriting ❌
```cpp
nums[i] = nums[(i+k) % n];
```
👉 Attempted to move data directly inside the array without a temporary hold. This permanently destroyed the unread data sitting at the destination index.

### 2. C++ Memory Crash (Empty Vector) ❌
```cpp
vector<int> ans;
ans[i] = ... 
```
👉 Declared an empty vector with 0 slots and immediately tried to write to index `i`. This caused a Segmentation Fault. 
👉 *Correction:* Always pre-allocate the slots: `vector<int> ans(n);`

### 3. Pull vs. Push (Math Inversion) ❌
```cpp
ans[i] = nums[(i+k) % n];
```
👉 I pulled data from the future into the current slot (a left rotation). 
👉 *Correction:* I needed to push data from the current slot into the future slot: `ans[(i+k) % n] = nums[i];`

### 4. Lifecycle Collision ❌
👉 Put the copy-back step (`nums[i] = ans[i]`) inside the exact same loop that was building the array. This re-introduced the overwrite bug. Separated them into sequential loops.

---

## 💡 Key Learnings
* **Modulo Arithmetic for Wrap-Around:** The formula `(current_index + shift_amount) % array_length` is the ultimate mathematical tool for any problem that requires arrays to loop back on themselves (circular arrays).
* **Memory Protection:** If a problem requires shifting lots of data simultaneously, an $O(n)$ space auxiliary array is the safest and most reliable way to prevent data corruption.

---

## 🔁 Pattern Identified
**Type:** Array / Modulo Arithmetic
Used in:
* Rotate Array
* Any circular queue or wrap-around string problem.

---

## ⏱️ Complexity
* **Time:** $O(n)$. We iterate through the array twice sequentially.
* **Space:** $O(n)$. We allocate a temporary array of the same size.

---

## 🏁 Final Takeaway
> Modulo `% length` is your best friend for circular array boundaries. Protect your data in a waiting room before copying it back.

