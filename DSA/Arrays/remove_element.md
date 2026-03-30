# 🧠 DSA Log — Remove Element (LeetCode 27)

## 📅 Date

2026-03-30

---

## 🚀 Problem

**Remove Element**

Given an array `nums` and a value `val`, remove all occurrences of `val` **in-place** and return the number of elements not equal to `val`.

---

## 🎯 Approach

### Idea

Use **two pointers**:

* `i` → iterate through array
* `k` → position to place valid elements

### Logic

* Traverse array
* If element != val → copy to index `k`
* Increment `k`

---

## 💻 Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3,2,3,2};
    int val = 2;

    int result = obj.removeElement(nums, val);

    cout << "Result: " << result << endl;

    cout << "Array after operation: ";
    for(int i = 0; i < result; i++){
        cout << nums[i] << " ";
    }

    return 0;
}
```

---

## 🧪 Example

Input:

```
nums = [3,2,3,2], val = 2
```

Output:

```
k = 2
nums = [3,3,_,_]
```

---

## 🐞 Mistakes I Made

### 1. Used `.size()` on C-array ❌

```cpp
int nums[4];
nums.size(); // ❌ invalid
```

✅ Fix:

* Use `vector`
* Or manually define size

---

### 2. Infinite recursion ❌

```cpp
int k = removeElement(nums, val); // ❌
```

👉 Calling function inside itself without base case

---

### 3. Misused variable `k` ❌

```cpp
k = nums[i]; // ❌ wrong
```

👉 Treated `k` as value instead of index

---

### 4. Misunderstood problem ❌

Thought:

> "remove elements"

Reality:

> "overwrite valid elements in-place"

---

## 💡 Key Learnings

* `vector` is preferred over C arrays in DSA
* In-place problems = **modify original array**
* Two-pointer pattern is very common
* Only first `k` elements matter

---

## 🔁 Pattern Identified

**Type:** Two Pointer (Overwrite Pattern)

Used in:

* Remove Element
* Move Zeroes
* Remove Duplicates

---

## ⏱️ Complexity

* Time: `O(n)`
* Space: `O(1)`

---

## 🧠 Thoughts

* Initially confused between value vs index
* Need to improve pointer thinking
* Writing code in VS Code helped catch real mistakes

---

