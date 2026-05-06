# 🧠 DSA Log — H-Index (LeetCode 274)

## 📅 Date
2026-05-06

---

## 🚀 Problem
**H-Index**
Given an array of integers `citations` where `citations[i]` is the number of citations a researcher received for their `i`th paper, return the researcher's h-index.
A researcher has an index `h` if they have published at least `h` papers that have each been cited at least `h` times.

---

## 🎯 Approach
### Idea
Use **Sorting + Threshold Tracking**:
* Stop thinking about frequency (how often a specific number appears). 
* Think of the papers like a GitHub profile: To claim an "H-Score" of 3, your top 3 repositories must *all* have at least 3 stars.
* If we sort the papers in descending order (best to worst), we can just walk down the list.
* At every step, we check if the current paper has enough citations to support increasing our total H-Index score.

---

## 💡 Logic
1.  **Sort** the `citations` array in descending (reverse) order.
2.  Initialize `hindex = 0`.
3.  Loop through the sorted array index by index.
4.  **The Claim Check:** `if(citations[i] > hindex)`
    * If the current paper has more citations than our current `hindex`, it proves we can safely increment our `hindex` by 1.
    * If the current paper does *not* have enough citations, it means we have reached the "weak" papers. Because the array is sorted, every subsequent paper will also fail this check. The `hindex` stops growing.
5.  Return the final `hindex`.

---

## 💻 Code
```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend()); // Sort in descending order
        int hindex = 0; // This will track our current H-Index score

        // Walk through the sorted citations
        for(int i = 0; i < citations.size(); i++){
            // Check if the current paper can support an H-Index of hindex + 1
            if(citations[i] > hindex){
                hindex++;
            }
        }
        return hindex;
    }
};
```

## 🐞 Mistakes I Made
### 1. The Boyer-Moore Frequency Trap ❌
👉 Initially attempted to solve this using the "King of the Hill" frequency counting logic from the *Majority Element* problem. 
👉 *Correction:* The H-Index is not about which exact number appears the most often. It is about a **threshold requirement** (e.g., 5 papers crossing the line of 5+ citations).

### 2. Misunderstanding the Math Jargon ❌
👉 Tried to dry-run the array `[0, 0, 2]` without sorting it, expecting the answer to be the maximum value (`2`). 
👉 *Correction:* You cannot have an H-Index of 2 if you only have one paper with citations. The metric demands a balance between quantity and quality. Sorting the array descending is mandatory to process the "best" papers first.

---

## 💡 Key Learnings
* **Translating Jargon:** When a problem uses dense mathematical definitions, translate it into a real-world analogy (like GitHub stars or YouTube views) before writing a single line of code.
* **Descending Sort for Thresholds:** If you need to find the "maximum valid streak" of something, sorting from highest to lowest makes the logic an incredibly simple $O(N)$ linear scan.

---

## ⏱️ Complexity
* **Time:** $O(N \log N)$. The bottleneck is the sorting algorithm. The `for` loop itself is only $O(N)$.
* **Space:** $O(1)$ to $O(\log N)$, depending on the C++ compiler's underlying sorting implementation.

---

## 🏁 Final Takeaway
> To find the H-Index, put your best work at the top of the resume, and count down until the quality drops below your current rank.

