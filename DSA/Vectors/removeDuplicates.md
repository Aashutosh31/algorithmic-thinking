# 🧠 DSA Log — Remove Duplicates from Sorted Array

## 📅 Date

2026-04-18

---

## 🚀 Problem

Given a sorted array `nums`, remove duplicates **in-place** such that each element appears **only once**.

Return the number of unique elements `k`.

---

## 🎯 Approach

### Idea

Use **two pointers**:

* `a` → last unique element (write pointer)
* `b` → scans array (read pointer)

---

## 💡 Logic

1. Start:

```
a = 0
```

2. Traverse:

```
for b = 1 → n-1
```

3. If new element found:

```
nums[a] != nums[b]
```

👉 Move `a` forward and copy element

---

## 💻 Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 0;
        int count = 1; // Count of unique elements

        for(int b = 1; b < nums.size(); b++){
            if(nums[a] != nums[b]){
                a++;
                nums[a] = nums[b];
            }
        }
        return count;
    }
};
```

---

## 🧪 Example

Input:

```
[1,1,2,2,3]
```

Output:

```
[1,2,3]
k = 3
```

---

## 💡 Key Learnings

* Sorted array → duplicates are adjacent
* Two-pointer overwrite technique
* `a` tracks last valid index

---

## ⏱️ Complexity

* Time: `O(n)`
* Space: `O(1)`

---

## 🏁 Final Takeaway

> Keep only new elements by shifting them forward.
