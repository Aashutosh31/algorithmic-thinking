# 🧠 DSA Log — Length of Last Word (LeetCode 58)

## 📅 Date

2026-05-10

---

## 🚀 Problem

**Length of Last Word**
Given a string `s` consisting of words and spaces, return the length of the **last** word in the string.
A word is a maximal substring consisting of non-space characters only. (Note: There may be trailing spaces at the end of the string).

---

## 🎯 Approach

### Idea: Reverse Iteration

* Since we only care about the *last* word, scanning the string from left to right is inefficient.
* We start at the very end of the string and iterate backwards.
* We need to handle two phases:
1. Skip any trailing spaces at the end of the string.
2. Count the characters of the first valid word we encounter, and stop the moment we hit the space immediately preceding that word.



---

## 💡 Logic

1. Initialize a counter `word = 0`.
2. Start a `for` loop from the last index (`s.length() - 1`) and step backwards (`i--`).
3. **Phase 1 & 2 (Counting):** `if (s[i] != ' ')`
* If the character is not a space, it belongs to the last word. Increment `word++`.


4. **The Kill Switch (Breaking the Loop):** `else if (s[i] == ' ' && word != 0)`
* If we hit a space, AND we have already started counting a word (`word != 0`), it means we just reached the space *before* the last word.
* We have successfully isolated the last word. `break;` the loop.
* *(Note: If `word == 0`, it means we are just seeing trailing spaces at the end of the string, so we do nothing and keep iterating backwards).*


5. Return `word`.

---

## 💻 Code

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int word = 0;
        
        // Start from the end of the string
        for(int i = s.length() - 1; i >= 0; i--){  
            
            // If it's a letter, count it.
            if(s[i] != ' ') {
                word++;
            }
            // If it's a space AND we already counted letters, we are done.
            else if(s[i] == ' ' && word != 0 ){
                break;
            }
        }
        
        return word;
    }
};

```

---

## ⏱️ Complexity

* **Time:** $O(N)$ in the absolute worst-case scenario (a string with only one word at the very beginning), but in reality, it runs in $O(L)$ where $L$ is the length of the last word plus any trailing spaces. It almost never scans the whole string.
* **Space:** $O(1)$. We only use a single integer variable for counting.

---

## 🏁 Final Takeaway

> When looking for the "last" element of a sequence, always try iterating in reverse.

