
# 🧠 DSA Log — 3Sum

## 📅 Date

2026-04-03

---

## 🚀 Problem

**3Sum**

Given an integer array `nums`, return all the **unique triplets** `[nums[i], nums[j], nums[k]]` such that:

```
nums[i] + nums[j] + nums[k] == 0
```

Constraints:

```
i != j, i != k, j != k
```

---

## 🎯 Approach

### Idea

Convert 3Sum → **Two Sum problem**

* Fix one number → `nums[i]`
* Find two numbers such that:

```
nums[j] + nums[k] = -nums[i]
```

---

## 💡 Logic

1. Sort the array:

```
sort(nums.begin(), nums.end())
```

2. Loop through array:

```
for i = 0 → n-2
```

3. Skip duplicates for `i`:

```
if(i > 0 && nums[i] == nums[i-1]) continue;
```

4. Use two pointers:

```
j = i + 1
k = n - 1
```

5. While `j < k`:

* If sum < 0 → move `j++`
* If sum > 0 → move `k--`
* If sum == 0:

  * store triplet
  * move both pointers
  * skip duplicates for `j` and `k`

---

## 💻 Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};
```

---

## 🧪 Example

Input:

```
nums = [2,3,-2,4,-2,2,1,2,-3]
```

Sorted:

```
[-3, -2, -2, 1, 2, 2, 2, 3, 4]
```

Output:

```
[-3, 1, 2]
[-2, -2, 4]
```

---

## 🐞 Mistakes I Made

### 1. Used `while` instead of `if` for duplicate `i` ❌

```cpp
while(i > 0 && nums[i] == nums[i - 1]) ❌
```

👉 Caused infinite loop risk

---

### 2. Didn’t understand duplicate skipping ❌

👉 Thought loops were skipping iterations
👉 Actually they move pointers forward/backward

---

### 3. Confusion from Two Sum ❌

👉 Expected only one loop
👉 Forgot 3Sum = Two Sum + extra loop

---

### 4. Printing vector<vector<int>> ❌

```cpp
cout << result[i]; ❌
```

👉 Needed nested loop

---

### 5. No spacing in output ❌

```cpp
-312 ❌
```

👉 Fixed by adding `" "`

---

## 💡 Key Learnings

* 3Sum = **Two Sum + one loop**
* Sorting helps:

  * use two pointers
  * detect duplicates easily
* Duplicate handling is critical:

  * `i` → avoid repeated starts
  * `j`, `k` → avoid repeated triplets
* `while` loops ≠ skipping iterations

  * they move pointers multiple times

---

## 🔁 Pattern Identified

**Type:** Two Pointer + Sorting

Used in:

* 3Sum
* 4Sum
* Subsets II
* Combination Sum II

---

## ⏱️ Complexity

* Time: `O(n^2)`
* Space: `O(1)` (excluding output)

---

## 🧠 Thoughts

* Initially confused about duplicate handling
* Big confusion: why extra loops?
* Breakthrough:

  * understanding 3Sum = Two Sum + fixed element
* Printing issue made output look wrong
* Concept became clear after debugging step-by-step

---

## 🏁 Final Takeaway

> Fix one → solve Two Sum → skip duplicates everywhere.
