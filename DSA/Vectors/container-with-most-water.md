# 🧠 DSA Log — Container With Most Water (LeetCode 11)

## 📅 Date

2026-04-19

---

## 🚀 Problem

**Container With Most Water**

Given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i`th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

---

## 🎯 Approach

### Idea

Use **Two Pointers (Opposite Ends)**:

* `left` → start of array (index 0)
* `right` → end of array (index n - 1)
* Start with the maximum possible width. To find a larger area, we must sacrifice width, so we only move the pointer pointing to the **shorter** line in hopes of finding a taller one.

---

## 💡 Logic

1. Initialize:

   * `left = 0`
   * `right = n - 1`
   * `area = 0`

2. Loop while `left < right`:

   * Calculate current water volume:

     ```cpp
     int Newarea = (right - left) * min(height[left], height[right]);
     ```

   * Update the maximum area tracking variable:

     ```cpp
     if (Newarea > area) { area = Newarea; }
     ```

   * Move the pointer of the shorter line:

     * If `height[left] < height[right]` → `left++`
     * Else → `right--`

---

## 💻 Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int left = 0;
        int right  = n - 1;

        while(left < right) { 
            int Newarea = (right - left) * min(height[left],height[right]);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }

            if(Newarea > area){
                area = Newarea;
            }
        }
        return area;
    }
};
```

---

## 🧪 Example

Input:

```
height = [1,8,6,2,5,4,8,3,7]
```

Steps:

* `left = 0` (height 1), `right = 8` (height 7). Width = 8. Area = 8 * 1 = 8.
* Move `left` because 1 < 7.
* `left = 1` (height 8), `right = 8` (height 7). Width = 7. Area = 7 * 7 = 49.
* Move `right` because 7 < 8.
* ... and so on.

Output:

```
49
```

---

## 🐞 Mistakes I Made

### 1. Brute Force Nested Loops ❌

```cpp
for(int i = 0; i < n; i++){
    for (int j = 1; j < n; j++){ ... }
}
```

👉 Resulted in O(n²) time complexity. Too slow for large inputs.

---

### 2. Overwriting state without comparing ❌

```cpp
area = (j - i) * min(height[i],height[j]);
```

👉 Forgot to track the maximum. The loop just returned the area of the very last pair checked.

---

### 3. Reversed State Update Logic ❌

```cpp
else if(newArea > area){
    newArea = area; 
}
```

👉 Wiped out the newly found maximum area by assigning the old `0` value to it.

---

### 4. Moving pointers based on Area instead of Height ❌

```cpp
if(newArea < area){ left++; }
else if(newArea > area){ right--; }
```

👉 This violates the physics of the problem. Pointers must move based on which wall is shorter (`height[left] < height[right]`), not whether the area grew or shrank.

---

## 💡 Key Learnings

* The water level is always bottlenecked by the `min()` of the two walls.
* There is **zero mathematical benefit** to keeping a short wall and moving a tall wall. You must throw away the short wall to have any chance of finding a deeper container.
* State tracking (`area = max(area, Newarea)`) must be completely decoupled from the logic that decides how to traverse the array (`left++` / `right--`).

---

## 🔁 Pattern Identified

**Type:** Two Pointer (Opposite Ends / Greedy Choice)

Used in:

* Two Sum II (Sorted)
* Container With Most Water
* Trapping Rain Water (Similar physics concepts)

---

## ⏱️ Complexity

* Time: `O(n)` (One single pass through the array)
* Space: `O(1)` (Only using a few integer variables)

---

## 🧠 Thoughts

* Experienced heavy frustration trying to translate the pointer movement logic from `Two Sum II` to this problem.
* Major block: trying to use the calculated `area` to dictate pointer movement.
* Breakthrough: stepping away from the code and visualizing the actual physical geometry of the walls.

---

## 🏁 Final Takeaway

> Always throw away the limiting factor (the shorter wall) when searching for a larger result.