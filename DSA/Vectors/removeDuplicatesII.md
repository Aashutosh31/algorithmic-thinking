# 🧠 DSA Log — Remove Duplicates II

## 📅 Date

2026-04-18

---

## 🚀 Problem

Given a sorted array `nums`, remove duplicates such that each element appears **at most twice**.

Return `k` (number of valid elements).

---

## 🎯 Approach

### Idea

Use:

* `a` → write pointer
* `b` → read pointer
* `count` → frequency of current number

---

## 💡 Logic

1. Initialize:

```
a = 0
count = 1
```

2. Traverse:

```
for b = 1 → n-1
```

---

### Case 1: Same number

```
nums[a] == nums[b]
```

* If `count < 2` → keep it
* else → skip

---

### Case 2: New number

```
nums[a] != nums[b]
```

* reset count
* write element

---

## 💻 Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 0;
        int count = 1;

        for(int b = 1; b < nums.size(); b++){
            if(nums[a] == nums[b] && count < 2){
                a++;
                nums[a] = nums[b];
                count++;
            }else if(nums[a] != nums[b]){
                count = 0;
                a++;
                nums[a] = nums[b];
                count++;
            }
        }
        return a + 1;
    }
};
```

---

## 🧪 Example

Input:

```
[1,1,1,2,2,3]
```

Output:

```
[1,1,2,2,3]
k = 5
```

---

## ⚠️ Common Mistakes

* Forgetting to reset `count` ❌
* Incrementing `b` manually inside loop ❌
* Using `<= nums.size()` ❌
* Returning `count` instead of length ❌

---

## 💡 Key Learnings

* Count is per **group**, not global
* Must handle:

  * new number
  * allowed duplicate
  * excess duplicate
* Still uses two-pointer overwrite pattern

---

## ⏱️ Complexity

* Time: `O(n)`
* Space: `O(1)`

---

## 🏁 Final Takeaway

> Allow duplicates up to limit, skip the rest.
