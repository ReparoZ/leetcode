// Source: https://leetcode.com/problems/minimum-window-substring/
// Author: ML3426
// Date: 2017-02-27

/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * 
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 滑动窗口法
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        int count = (int) t.length();
        int require[128] = {0};
        bool chSet[128] = {false};

        for (int i = 0; i < t.size(); ++i) require[t[i]]++, chSet[t[i]] = true;

        int left = 0, right = -1, minLen = INT_MAX, minIdx = 0;

        while (left < s.length() && right < int(s.length())) {
            if (count) {
                right++;
                require[s[right]]--;
                if (chSet[s[right]] && require[s[right]] >= 0) count--;
            } else {
                if (minLen > right - left + 1) minLen = right - left + 1, minIdx = left;
                require[s[left]]++;
                if (chSet[s[left]] && require[s[left]] > 0) count++;
                left++;
            }
        }
        
        if (minLen == INT_MAX) return "";
        return s.substr((unsigned long) minIdx, (unsigned long) minLen);
    }
};