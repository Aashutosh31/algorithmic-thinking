# 🧠 DSA Log — Roman to Integer (LeetCode 13)

## 📅 Date
2026-05-15

---

## 🚀 Problem
**Roman to Integer**
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D`, and `M`. 
Given a roman numeral string, convert it to an integer.
*Rule:* Roman numerals are usually written largest to smallest from left to right. However, if a smaller numeral appears *before* a larger numeral, it indicates subtraction (e.g., `IV` is 4, not 6).

---

## 🎯 Approach
### Idea: The "Translator + Accountant" Architecture (Look-Ahead)
* **The Problem with Looking Backwards:** Trying to check `s[i - 1]` leads to out-of-bounds memory crashes on the first loop.
* **The Solution:** Look *forward*. Check the current letter and the *next* letter. 
* **Separation of Concerns:** Trying to translate the letter and do the math in the same massive `if/else` block causes logic to get eaten or duplicated. 
    * Build a separate **Translator** helper function just to convert `char` to `int`.
    * The main function acts as the **Accountant**, strictly handling the math based on the Look-Ahead rule.

---

## 💡 Logic
1.  **The Translator:** Create a helper function with a `switch` statement that returns the integer value of a Roman character.
2.  **The Accountant Loop:** Iterate through the string, but **stop one character early** (`i < s.length() - 1`) to safely use `s[i+1]` without crashing.
3.  **The Look-Ahead Math:**
    * Get `current` value from the Translator.
    * Get `next` value from the Translator.
    * If `current < next` ➔ We are in a subtraction state (e.g., `I` before `V`). Subtract `current` from the total.
    * If `current >= next` ➔ Standard state. Add `current` to the total.
4.  **The Abandoned Last Letter:** Because the loop stops early, manually translate the very last letter of the string and **add** it to the total (the final letter of a Roman numeral is physically impossible to subtract).

---

## 💻 Code
```cpp
class Solution {
public:
    // --- THE TRANSLATOR ---
    // Pure function: Takes a char, returns an int. Does absolutely no math.
    int translator(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    // --- THE ACCOUNTANT ---
    int romanToInt(string s) {
        int number = 0;
        
        // Stop at length - 1 so s[i+1] never goes out of bounds
        for(int i = 0; i < s.length() - 1; i++){
            int current = translator(s[i]);
            int next = translator(s[i+1]);

            // The Look-Ahead Rule
            if(current >= next){
                number += current;
            } else if(current < next){
                number -= current;
            }
        }
        
        // The last letter is always added
        int lastLetterValue = translator(s[s.length() - 1]);
        number = number + lastLetterValue;
        
        return number;
    }
};

```

---

## 🐞 Mistakes I Made & Traps Avoided (The 2-Hour Struggle)

### 1. The "Eaten Alive" Trap (Top-Down Execution) ❌

* **What I did:** Wrote simple checks like `if (s[i] == 'V')` at the top of my loop, and complex checks like `else if (s[i] == 'V' && s[i - 1] == 'I')` at the bottom.
* **Why it failed:** Computers execute strictly top-to-bottom. If it saw a 'V', it triggered the simple check, added 5, and entirely skipped the complex check at the bottom.

### 2. Looking Backward Memory Crash ❌

* **What I did:** Used `s[i - 1]` to check previous characters.
* **Why it failed:** On the very first loop (`i = 0`), checking index `-1` reads unallocated memory and causes a crash.
* **The Fix:** Look *ahead* (`s[i + 1]`) and stop the loop one step early.

### 3. The ASCII Trap (Comparing Letters, Not Numbers) ❌

* **What I did:** Wrote `if(s[i + 1] < s[i])`.
* **Why it failed:** This compares the ASCII alphabet values, not the Roman numeral values. ('L' is 76 in ASCII, 'X' is 88. The computer thinks 'L' < 'X', breaking the math).
* **The Fix:** Must translate both letters into integers *before* comparing them.

### 4. The Double Math Trap ❌

* **What I did:** Added to `number` inside the switch statement, and then subtracted from `number` again outside the switch statement.
* **Why it failed:** Math gets corrupted when mixing state management.
* **The Fix:** Decouple them entirely. Switch statement *only* returns a value. Main loop *only* does math.

### 5. The Abandoned Last Letter ❌

* **What I did:** Stopped the loop at `length - 1` but forgot to process the final letter.
* **The Fix:** Grab the last index manually after the loop, run it through the Translator, and add it.

---

## ⏱️ Complexity

* **Time:** $O(N)$ where $N$ is the length of the string. We scan the string exactly once. The dictionary lookup is $O(1)$.
* **Space:** $O(1)$. We only use a few integers to store running totals.

---

## 🏁 Final Takeaway

> To build a clean parser, never mix translation with calculation. Build a Translator to read the symbols, and an Accountant to do the math based on the Look-Ahead rule.
