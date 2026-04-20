Stop right there. Never feel bad about looking up a standard library function. 

You correctly identified the **logical requirement** (we need to skip characters that don't matter). You just didn't know the specific C++ **syntax** to do it (`isalnum`). 

An engineer doesn't memorize the dictionary; an engineer figures out what tool is missing and then goes to the documentation to find it. Searching the internet for "how to check if char is alphanumeric in C++" is exactly the right move.

Let's look at the code you integrated:
```cpp
while(left < right && !isalnum(s[left])) left++;
```
You should understand *why* this is written as a `while` loop and not an `if` statement. If you have multiple spaces in a row (e.g., `"a    b"`), an `if` statement only skips one space. The `while` loop acts as a "fast-forward" button, skipping everything until it hits a valid letter. 

Also, notice the `left < right` condition inside that inner `while` loop. That is a critical safety check. If the string is entirely punctuation (e.g., `"., ,."`), the pointer would just keep incrementing until it crashed out of bounds. That `left < right` boundary check prevents a segmentation fault.

You successfully implemented a **Two-Pointer with Conditional Fast-Forward**. 

Here is the documentation for your repository.

***

# 🧠 DSA Log — Valid Palindrome (LeetCode 125)

## 📅 Date
2026-04-20

---

## 🚀 Problem
**Valid Palindrome**
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

---

## 🎯 Approach
### Idea
Use **Two Pointers (Opposite Ends)**:
* `left` → starts at index `0`.
* `right` → starts at `s.length() - 1`.
* Move inward. If a pointer lands on a space or punctuation, "fast-forward" it until it hits a valid letter or number.
* Compare the valid characters.

---

## 💡 Logic
1. Initialize `left` and `right` pointers.
2. Main loop: `while (left < right)`
3. Fast-forward `left`: 
   * `while(left < right && !isalnum(s[left])) left++;`
4. Fast-forward `right`:
   * `while(left < right && !isalnum(s[right])) right--;`
5. Compare the lowercased versions:
   * `if (tolower(s[left]) != tolower(s[right])) return false;`
6. Move both pointers inward and repeat.
7. Return `true` if the loop finishes without mismatches.

---

## 💻 Code
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right) {
            // Skip non-alphanumeric characters from the left
            while(left < right && !isalnum(s[left])) left++;
            
            // Skip non-alphanumeric characters from the right
            while(left < right && !isalnum(s[right])) right--;

            // Compare valid characters
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```

---

## 🧪 Example
Input:
`s = "A man, a plan, a canal: Panama"`

Steps:
* `left` at 'A', `right` at 'a' → match (with `tolower`). `left++`, `right--`.
* `left` at ' ', `right` at 'm' → `left` hits space. Inner `while` loop triggers and skips the space. `left` lands on 'm'.
* 'm' == 'm' → match.
* Continues inward, skipping commas and colons dynamically.

---

## 🐞 Mistakes I Made
### 1. Ignored Problem Constraints ❌
👉 Attempted to compare every single character directly, forgetting that the problem explicitly stated to ignore non-alphanumeric characters. Resulted in failing basic test cases like Example 1.

### 2. Syntax Gap ❌
👉 Did not initially know the C++ standard library functions for character evaluation.
👉 *Correction*: Looked up and learned `isalnum()` (is alphanumeric) and `tolower()` (convert to lowercase).

### 3. incremented right pointer in the wrong direction ❌
👉 Accidentally wrote `right++` instead of `right--` when trying to move the 
right pointer inward. This would have caused an infinite loop or out-of-bounds access.
👉 *Correction*: Fixed to `right--` to ensure the pointer moves towards the center.
---

## 💡 Key Learnings
* **Conditional Fast-Forwarding:** You can embed `while` loops inside a main two-pointer `while` loop to skip over useless data quickly.
* **Boundary Safety:** When using inner loops to advance pointers, ALWAYS include the `left < right` boundary check inside the inner loop's condition to prevent out-of-bounds memory access (e.g., if the string is just `"   "`).
* **C++ Standard Library:** `isalnum()` and `tolower()` are essential tools for string parsing.

---

## 🔁 Pattern Identified
**Type:** Two Pointer (Opposite Ends + Fast-Forward)
Used in:
* Valid Palindrome
* Any parsing problem requiring skipping specific characters.

---

## ⏱️ Complexity
* **Time:** $O(n)$ where $n$ is the length of the string. Each character is visited at most once.
* **Space:** $O(1)$ constant extra space.

---

## 🏁 Final Takeaway
> Don't process garbage data. Fast-forward your pointers past it.
