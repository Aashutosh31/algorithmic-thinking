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

* Sorting is REQUIRED to:

  * apply two-pointer technique
  * decide pointer movement (increase/decrease sum)
  * handle duplicates easily

---

2. Loop through array:

```
for i = 0 → n-2
```

3. Skip duplicates for `i` (before processing):

```
if(i > 0 && nums[i] == nums[i - 1]) continue;
```

---

4. Use two pointers:

```
j = i + 1
k = n - 1
```

5. Condition:

```
while(j < k)  // compare indices, NOT values
```

---

6. Inside loop:

* If sum < 0 → move `j++`
* If sum > 0 → move `k--`
* If sum == 0:

  * store triplet
  * move both pointers
  * skip duplicates for `j` and `k`

---

## 🔁 Duplicate Handling

### For `i`:

* Skip BEFORE processing
* Avoid starting from same value again

```
if(i > 0 && nums[i] == nums[i - 1]) continue;
```

---

### For `j` and `k`:

* Skip ONLY AFTER finding a valid triplet
* Prevent duplicate triplets

```
j++;
k--;

while(j < k && nums[j] == nums[j - 1]) j++;
while(j < k && nums[k] == nums[k + 1]) k--;
```

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

## ⚠️ Common Misconceptions

* `j < k` is based on indices, NOT values

* `nums[j] == nums[k]` does NOT stop the loop

* Duplicate skipping:

  * does NOT skip valid answers
  * only skips already-used values after a valid triplet

* Algorithm works without duplicate skipping,
  but produces duplicate results ❌

---

## 🐞 Mistakes I Made

### 1. Used `while` instead of `if` for duplicate `i` ❌

```
while(i > 0 && nums[i] == nums[i - 1]) ❌
```

👉 Caused infinite loop risk

---

### 2. Didn’t understand duplicate skipping ❌

👉 Thought loops were skipping iterations
👉 Actually they skip repeated results

---

### 3. Confusion from Two Sum ❌

👉 Expected only one loop
👉 Forgot 3Sum = Two Sum + extra loop

---

### 4. Printing vector<vector<int>> ❌

```
cout << result[i]; ❌
```

👉 Needed nested loop

---

### 5. No spacing in output ❌

```
-312 ❌
```

👉 Fixed by adding `" "`

---

### 6. Thought duplicate skipping skips valid cases ❌

👉 Actually skips only repeated results, not possibilities

---

## 💡 Key Learnings

* 3Sum = **Two Sum + one loop**
* Sorting enables two-pointer logic
* Duplicate handling is critical:

  * `i` → avoid repeated starts
  * `j`, `k` → avoid repeated triplets
* Skip duplicates only after using them once successfully
* Loop runs on indices, not values

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
* Learned difference between:

  * skipping values vs skipping results

---

## 🏁 Final Takeaway

> Fix one → solve Two Sum → skip duplicates ONLY after using them.
