# 🧠 DSA Log — Two Sum II (Input Array Is Sorted)

## 📅 Date

2026-03-31

---

## 🚀 Problem

**Two Sum II — Input Array Is Sorted**

Given a **1-indexed** array of integers `numbers` that is sorted in non-decreasing order, find two numbers such that they add up to a specific `target`.

Return the indices of the two numbers (`index1`, `index2`) such that:

```
1 <= index1 < index2 <= numbers.length
```

---

## 🎯 Approach

### Idea

Use **Two Pointers (Opposite Ends)**:

* `index1` → start of array (smallest)
* `index2` → end of array (largest)

---

## 💡 Logic

1. Initialize:

   * `index1 = 0`
   * `index2 = n - 1`

2. Loop while `index1 < index2`:

   * Compute sum:

     ```
     sum = numbers[index1] + numbers[index2]
     ```

3. Compare:

   * If `sum > target` → decrease `index2`
   * If `sum < target` → increase `index1`
   * If `sum == target` → return answer

---

## 💻 Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;

        while (index1 < index2) {
            if (numbers[index1] + numbers[index2] > target) {
                index2--;
            } 
            else if (numbers[index1] + numbers[index2] < target) {
                index1++;
            } 
            else {
                return {index1 + 1, index2 + 1};
            }
        }

        return {index1 + 1, index2 + 1};
    }
};
```

---

## 🧪 Example

Input:

```
numbers = [2,7,11,15], target = 9
```

Steps:

```
2 + 15 = 17 → too big → move right
2 + 11 = 13 → too big → move right
2 + 7  = 9  → found
```

Output:

```
[1,2]
```

---

## 🐞 Mistakes I Made

### 1. Treated `target` as index ❌

```cpp
numbers[target] ❌
```

👉 Mistake: confused **value vs index**

---

### 2. Started both pointers at 0 ❌

```cpp
int index1 = 0;
int index2 = 0;
```

👉 Used same element twice

---

### 3. No loop ❌

👉 Only checked once instead of iterating

---

### 4. Used wrong index bounds ❌

```cpp
int index2 = numbers.size(); // ❌ out of bounds
```

---

### 5. Missed stopping condition ❌

```cpp
while(index1 <= index2) // ❌ allows same index
```

---

### 6. Inconsistent return indexing ❌

```cpp
return {index1, index2}; // ❌
```

👉 Problem requires **1-based indexing**

---

## 💡 Key Learnings

* Sorted array allows **smart pointer movement**
* Two pointer ≠ always same direction
* Always clarify:

  * index vs value
  * 0-based vs 1-based
* Don’t jump to code → simulate first

---

## 🔁 Pattern Identified

**Type:** Two Pointer (Opposite Ends)

Used in:

* Two Sum II
* Container With Most Water
* 3Sum (extension)

---

## ⏱️ Complexity

* Time: `O(n)`
* Space: `O(1)`

---

## 🧠 Thoughts

* Initially frustrated due to misunderstanding
* Major confusion: index vs value
* Breakthrough came after manual simulation
* Learned how to **use constraints (sorted array)** effectively

---

## 🚀 Next Steps

* Remove Duplicates from Sorted Array
* Move Zeroes
* Container With Most Water

---

## 🏁 Final Takeaway

> Don’t just check conditions — use them to make decisions

---
