# 🧠 DSA Log — Longest Common Prefix (LeetCode 14)

## 📅 Date

2026-05-10

---

## 🚀 Problem

**Longest Common Prefix**
Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string `""`.

---

## 🎯 Approach

### Idea: Vertical Scanning

* Do not compare strings horizontally (word by word), as you might accumulate a prefix that doesn't exist in later words.
* Instead, scan vertically (column by column).
* Imagine the strings stacked on top of each other. Check index 0 of every string, then index 1, then index 2.
* Use the very first string (`strs[0]`) as the baseline.
* The moment any string's character doesn't match the baseline, or a string runs out of characters, the prefix ends.

---

## 💡 Logic

1. **The Outer Loop (Columns):** Iterate `j` from `0` up to the length of the baseline word `strs[0]`.
2. **The Inner Loop (Rows):** Iterate `i` starting from `1` (skipping the baseline word) up to the total number of strings in the array.
3. **The Emergency Alarm:** Inside the inner loop, check for two things:
* *Out of Ammo:* Has `j` reached the length of the current string `strs[i]`? (Meaning the current string is shorter than the baseline and we just ran out of letters).
* *Mismatch:* Does `strs[i][j]` differ from `strs[0][j]`?


4. **The Short-Circuit Escape:** If the alarm triggers, immediately `return` the substring of the baseline word from index `0` to `j`. Do **not** use `break`, as that only kills the inner loop.
5. **The Victory Condition:** If the outer loop finishes completely, it means every letter of the baseline word perfectly matched every other word. Return the entire baseline word `strs[0]`.

---

## 💻 Code

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: Vertical Scanner (Columns)
        for(int j = 0; j < strs[0].length(); j++){
            
            // Step 2: Check every other string (Rows)
            for(int i = 1; i < strs.size(); i++){
                
                // Step 3: The Emergency Alarm
                // CRITICAL: Always check length BEFORE checking the character!
                if(j == strs[i].length() || strs[i][j] != strs[0][j]){
                    return strs[0].substr(0,j); // Eject from the function entirely
                }
            }
        }
        // Step 4: Survived the whole gauntlet (e.g., ["a"] or ["flower", "flower"])
        return strs[0];
    }
};

```

---

## 🐞 Mistakes I Made & Traps Avoided

### 1. The "Psychic" Bug (Hardcoding limits) ❌

* **What I did:** Hardcoded `j < 2` assuming the prefix would be exactly 2 characters.
* **The Fix:** Let the data dictate the length. Use `strs[0].length()` as the absolute maximum possible boundary.

### 2. The "Soft Kill" (Nested Loop Trap) ❌

* **What I did:** Used `break;` when a mismatch was found.
* **Why it failed:** `break` only terminates the immediate inner loop. The outer loop just incremented `j` and kept checking the next column, leading to a garbled prefix.
* **The Fix:** Used `return` to completely eject from the function the exact millisecond the prefix was broken.

### 3. Reading the Void (Memory Crash & Order of Operations) ❌

* **What I did:** Wrote `if(strs[i][j] != strs[0][j] || j == strs[i].length())`.
* **Why it failed:** C++ reads `||` from left to right. If `strs[i]` is too short, trying to read `strs[i][j]` will cause an "Out of Bounds" memory crash before it ever checks the length.
* **The Fix:** Flipped the condition to `if(j == strs[i].length() || ...)`. Because of C++ "short-circuiting", if the first condition is True (out of ammo), it triggers the alarm without ever attempting to read the illegal memory space.

### 4. The Single Word Trap ❌

* **What I did:** Returned `""` at the very end of the function.
* **Why it failed:** On test case `["a"]`, the inner loop never runs. The outer loop finishes, hits the bottom, and returns empty string instead of `"a"`.
* **The Fix:** If the code survives all loops, it means the entire baseline word is valid. `return strs[0];`.

---

## ⏱️ Complexity

* **Time:** $O(S)$, where $S$ is the sum of all characters in all strings. In the worst case, all strings are identical, and we have to physically check every single character of every string.
* **Space:** $O(1)$. We only used constant extra space to store our pointers.

---

## 🏁 Final Takeaway

> When comparing multiple sequences, don't build a massive horizontal snowball. Stack them up and scan vertically, failing as early as possible.