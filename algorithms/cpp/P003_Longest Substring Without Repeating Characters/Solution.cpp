// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: ML3426
// Date: 2017-01-17

/* 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 滑动窗口法(Optimized)
    // 时间复杂度：O(n)，空间复杂度：O(min(m, n))
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, last_repeat_pos = -1;
        unordered_map<char, int> pos_map;
        for (int i = 0; i < s.length(); ++i) {
            if (pos_map.find(s[i]) != pos_map.end() && last_repeat_pos < pos_map[s[i]]) {
                last_repeat_pos = pos_map[s[i]];
            }
            
            if (maxLen < i - last_repeat_pos) {
                maxLen = i - last_repeat_pos;
            }
            
            pos_map[s[i]] = i;
        }
        
        return maxLen;
    }
};