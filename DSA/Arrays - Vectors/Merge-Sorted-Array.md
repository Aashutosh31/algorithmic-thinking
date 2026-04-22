# 🧠 DSA Log — Merge Sorted Array (LeetCode 88)

## 📅 Date
2026-04-22

---

## 🚀 Problem
**Merge Sorted Array**
You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.
Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. `nums1` has a length of `m + n`, where the first `m` elements are the real data, and the last `n` elements are set to `0` and should be ignored.

---

## 🎯 Approach
### Idea
Use **Two Pointers (Three-Pointer Backwards Merge)**:
* If we start merging from the front, we will overwrite the existing data in `nums1` before we can compare it.
* To prevent data destruction, we must build the array **backwards**, starting from the empty `0` buckets at the end of `nums1`.
* We use three pointers: one for the end of the real data in `nums1`, one for the end of `nums2`, and one for the very last empty bucket.

---

## 💡 Logic
1. Initialize three pointers based on zero-indexed math:
   * `i = m - 1` (Last real number in `nums1`)
   * `j = n - 1` (Last real number in `nums2`)
   * `k = m + n - 1` (The absolute last empty bucket)
2. **Main Merge Loop:** `while(j >= 0 && i >= 0)`
   * Compare `nums1[i]` and `nums2[j]`.
   * Drop the **larger** number into the bucket at `nums1[k]`.
   * Decrement `k` and whichever pointer (`i` or `j`) you just pulled the number from.
3. **Cleanup Loop:** `while(j >= 0)`
   * If `nums1` runs out of numbers first (`i` drops below zero), the main loop breaks. We must sweep any remaining numbers sitting in `nums2` directly into the remaining slots of `nums1`.
   * *(Note: If `nums2` runs out first, we do nothing, because the remaining `nums1` numbers are already sitting perfectly sorted at the front).*

---

## 💻 Code
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Main loop: compare and place the largest at the back
        while(j >= 0 && i >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        } 
        
        // Cleanup loop: Sweep any leftover numbers from nums2
        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};
```

---

## 🐞 Mistakes I Made
### 1. The Vector Method Trap ❌
```cpp
while(nums2[n].size() == 0)
```
👉 Tried to call `.size()` on a single integer element instead of the vector itself. C++ syntax requires knowing exactly what data type you are operating on.

### 2. Forward Overwriting ❌
👉 Attempted to move pointers forward (`i++`, `j++`). This destroyed the unread data in `nums1` and violated the entire physics of the problem. Must build backwards.

### 3. Infinite Loops & Zero-Index Traps ❌
```cpp
while(j != 0) // Missed the 0th element
```
👉 Arrays are zero-indexed. Stopping at `0` means skipping the very first element. The condition must be `>= 0`.

### 4. Nesting Sequential Loops ❌
👉 Accidentally wrote the cleanup loop *inside* the main `while` loop. This broke the sequence. 
👉 *Correction*: Sequential loops (one after the other) are $O(N)$. Nested loops (one inside the other) are $O(N^2)$. Keep them separated.

---

## 💡 Key Learnings
* **Physical Memory:** Visualizing the actual array slots (the `0`s at the end) dictates the algorithm. 
* **Sequential Loops are Optimal:** Writing two `while` loops back-to-back does not ruin time complexity. $O(M) + O(N)$ is still an $O(N)$ linear time operation.

---

## 🔁 Pattern Identified
**Type:** Two Pointer (Backwards Traversal)
Used in:
* Merge Sorted Array
* Any problem where modifying an array in-place from the front causes data overwrites.

---

## ⏱️ Complexity
* **Time:** $O(m + n)$. We iterate through the elements exactly once.
* **Space:** $O(1)$. We sort the arrays in-place without allocating any extra memory.

---

## 🏁 Final Takeaway
> If going forwards destroys your data, build it backwards.
