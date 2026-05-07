# 🧠 DSA Log — Find the Index of the First Occurrence in a String (LeetCode 28)

## 📅 Date
2026-05-07

---

## 🚀 Problem
**Find the Index of the First Occurrence in a String (strStr)**
Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

---

## 🎯 Approach
### Idea: The Sliding Window (Anchor & Scout)
* Computers are "blind" and can only read one letter at a time. We cannot just scan forward endlessly.
* We need an **Anchor** (an outer loop) to mark the starting index of our current attempt.
* We need a **Scout** (an inner loop) to act as a measuring tape, checking the letters one by one from the Anchor.
* If a letter mismatches, the Scout dies, the Anchor pulls up and moves exactly one space to the right, and the Scout resets to zero for a fresh attempt.

---

## 💡 Logic & Core Concepts
1.  **The Space Limit (`hlen - nlen`):** * You don't need to check every single letter of the haystack. If your `needle` is 5 letters long, and you only have 4 letters left in the `haystack`, it is physically impossible for the word to fit. 
    * We stop the outer loop at `haystack.length() - needle.length()` to prevent doing useless work and to prevent "Out of Bounds" memory crashes.
2.  **The Math of Checking (`haystack[i + j]`):**
    * `i` is the Anchor. `j` is the distance from the Anchor. 
    * By checking `haystack[i + j]`, we can look ahead in the text without ever moving `i`. If the match fails, `i` is still safely planted exactly where the attempt started.
3.  **The Reset:** * If `haystack[i + j] != needle[j]`, we `break` the inner loop. The outer loop naturally increments `i` to start the next attempt, and `j` is reset to `0`.
4.  **The Victory Condition:** * If the inner loop finishes without breaking, it means `j` successfully counted up to the exact length of the needle. We found the word! Return the Anchor `i`.

---

## 💻 Code
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        
        // Protect against the Unsigned Integer underflow trap
        int hlen = haystack.length();
        int nlen = needle.length();
        
        // The Anchor (stops if there isn't enough physical space left)
        for(int i = 0; i <= hlen - nlen; i++){
            
            // The Scout (resets to 0 on every new attempt)
            for(j = 0; j < nlen; j++){
                
                // Mismatch? Kill the scout immediately.
                if(haystack[i+j] != needle[j]){
                      break; 
                }              
            }
            
            // Did the scout survive the whole length of the needle?
            if(j == nlen) return i;
        }
        
        // Checked every valid starting point and found nothing.
        return -1;
    }
};
```

---

## 🐞 Mistakes I Made & Traps Avoided

### 1. The "Mississippi" Trap (No Reset) ❌
* **What I did:** Used a single `while` loop, and on a mismatch, I did `i++` but forgot to reset `j`.
* **Why it failed:** When checking "issip" inside "mississippi", the code partially matched "issi", but failed on "p". Because `j` never reset, it got permanently stuck looking for "p" for the rest of the string, completely missing the second "issip".
* **The Fix:** Separated the logic into TWO loops. The outer loop creates a "save point," so `j` naturally resets to `0` on every new starting letter.

### 2. Dragging the Anchor ❌
* **What I did:** Inside my success check, I tried to increment `i++` alongside `j++`.
* **Why it failed:** If you move your anchor while you are measuring, you lose track of where the word actually started. 
* **The Fix:** Use the math `haystack[i + j]`. This automatically looks forward in the string without moving the `i` pointer.

### 3. The C++ `for` Loop Double-Step ❌
* **What I did:** Wrote `j++` inside the `if` block of a `for` loop.
* **Why it failed:** A `for` loop already increments `j` at the end of every cycle. Adding `j++` inside the block caused it to increment twice, skipping letters entirely.

### 4. The Clone Variable (Scope Issue) ❌
* **What I did:** Declared `for(int j = 0; ...)` inside the outer loop, and then tried to check `if(j == needle.length())` outside of it.
* **Why it failed:** Declaring `int j` inside the loop creates a temporary clone that gets destroyed the moment the loop breaks. The victory check outside the loop was looking at a different `j` entirely.
* **The Fix:** Declare `int j = 0;` at the very top of the function, and just use `j = 0` in the loop so the memory persists.

### 5. The Unsigned Integer Underflow (Language Gotcha) ❌
* **What it is:** In C++, `.length()` returns an *unsigned* integer (a number that cannot be negative). If the haystack is shorter than the needle (e.g., `2 - 5`), the math results in `-3`. But because it cannot be negative, C++ wraps it around to a massive number (`18,446,744...`), causing an infinite loop/crash.
* **The Fix:** Save the lengths into standard `int` variables before doing the loop math.

---

## ⏱️ Complexity
* **Time:** $O(N \cdot M)$ where $N$ is haystack length and $M$ is needle length. In the worst-case scenario (e.g., `haystack = "aaaaaaaaab"`, `needle = "aaab"`), the inner loop has to scan almost the whole needle before failing, over and over again.
* **Space:** $O(1)$. We only use a few integer variables for pointers.

---

## 🏁 Final Takeaway
> To find a word inside a word, plant an anchor, send out a scout, and use `i + j` to check the letters. If it fails, pull up the anchor, move one step right, and try again.

