// Source: https://leetcode.com/problems/implement-strstr/
// Author: ML3426
// Date: 2017-02-10

/*
 * Implement strStr().
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 按字符匹配
    // 循环的终止条件是（i > haystack.length() - needle.length()）
    // 时间复杂度为O(N^2)，空间复杂度为O(1)
    // Time: 6ms
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (haystack.length() < needle.length()) return -1;

        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (cmpStr(haystack, needle, i)) return i;
        }

        return -1;
    }

    bool cmpStr(string haystack, string needle, int offset) {
        for (int i = 0; i < needle.length(); ++i) {
            if (haystack[offset + i] != needle[i]) {
                return false;
            }
        }
        return true;
    }
};