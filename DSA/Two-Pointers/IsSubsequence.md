# 🧠 DSA Log — Is Subsequence (LeetCode 392)

## 📅 Date
2026-04-20

---

## 🚀 Problem
**Is Subsequence**
Given two strings `s` and `t`, return `true` if `s` is a subsequence of `t`, or `false` otherwise.
A subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.

---

## 🎯 Approach
### Idea
Use **Two Pointers (Scanning/Matching)**:
* `i` → tracks the current target character in string `s`.
* `j` → scans through string `t` to find matches.
* Instead of physically deleting characters in `t` (which is an expensive $O(N)$ memory operation), use the `j` pointer to simply "skip" non-matching characters.

---

## 💡 Logic
1. Initialize both pointers at `0`.
2. Loop while `j` has not reached the end of `t` **AND** `i` has not reached the end of `s` (Early Exit condition).
3. Compare `s[i]` and `t[j]`:
   * If match → Move both pointers (`i++`, `j++`).
   * If no match → Move only the scanning pointer (`j++`).
4. After the loop, check if pointer `i` successfully reached the end of string `s` (`i == s.length()`).

---

## 💻 Code
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        // Loop runs as long as there are characters left to check in BOTH strings
        while (j < t.length() && i < s.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        
        // If 'i' reached the length of 's', we found all characters in order
        return i == s.length();
    }
};
```

---

## 🧪 Example
Input:
`s = "abc"`, `t = "ahbgdc"`

Steps:
* `a` == `a` → match! `i`=1, `j`=1
* `b` != `h` → skip. `i`=1, `j`=2
* `b` == `b` → match! `i`=2, `j`=3
* `c` != `g` → skip. `i`=2, `j`=4
* `c` != `d` → skip. `i`=2, `j`=5
* `c` == `c` → match! `i`=3, `j`=6
* Loop breaks because `i` reached `s.length()`. Return `true`.

---

## 🐞 Mistakes I Made
### 1. The Infinite Loop Trap ❌
```cpp
if(s[i] == t[j]) continue;
```
👉 Used `continue` without incrementing pointers. Resulted in comparing the exact same characters forever.

### 2. Physical Deletion vs. Skipping ❌
👉 Initially thought about deleting characters from `t`. 
👉 *Correction*: Deleting characters from a string shifts memory ($O(n)$). Moving a pointer to skip a character is $O(1)$.

### 3. Missing the Early Exit ❌
```cpp
while(j < t.length())
```
👉 The loop kept scanning `t` even if the entire subsequence `s` was already found early on. Added `&& i < s.length()` to stop unnecessary iterations.

### 4. Type Coercion on Return ❌
```cpp
return s.length() + 1;
```
👉 Attempted to return an integer for a `bool` function. C++ evaluates any non-zero integer as `true`, causing the function to always pass regardless of logic. 

---

## 💡 Key Learnings
* **Implicit Sequence:** Because the scanning pointer `j` only moves forward, the relative order of characters is automatically maintained.
* **Early Exit Strategy:** Always check if you've already found the answer before continuing a loop. It prevents unnecessary execution time.
* **Boolean Returns:** You can return a conditional evaluation directly (e.g., `return i == s.length();`) rather than using verbose `if/else` blocks.

---

## 🔁 Pattern Identified
**Type:** Two Pointer (Scanning / Fast-Slow)
Used in:
* Is Subsequence
* Move Zeroes
* Valid Palindrome 

---

## ⏱️ Complexity
* **Time:** $O(T)$ where $T$ is the length of string `t`. We scan the string at most once.
* **Space:** $O(1)$ constant extra space.

---

## 🏁 Final Takeaway
> Don't delete memory when you can just point past it.