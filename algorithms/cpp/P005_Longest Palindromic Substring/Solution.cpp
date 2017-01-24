// Source: https://leetcode.com/problems/longest-palindromic-substring/
// Author: ML3426
// Date: 2017-01-22

/* 
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 中轴扩展法：
    // 回文串因为其自身结构，因此一定会有一个中轴，而中轴可能是某个字母，例如回文串"aba"，也可能是某两个字符中间，如"ab|ba"
    // 因此遍历每一个可能成为中轴的地方，从中轴开始向两方比对字符，并记录端点。
    // 时间复杂度:O(n^2) 空间复杂度:O(1)
    // Time: 36ms
    string longestPalindrome1(string s) {
        pair<unsigned long, unsigned long> max_strBounds;

        for (double i = 0.5; i < s.length(); i += 0.5) {
            auto bounds = getPalindromeBound(s, i);
            if (bounds.second - bounds.first > max_strBounds.second - max_strBounds.first) {
                max_strBounds = bounds;
            }
        }

        return s.substr(max_strBounds.first, max_strBounds.second - max_strBounds.first + 1);
    }

    pair<unsigned long, unsigned long> getPalindromeBound(string s, double middle) {
        double offset = middle == int(middle) ? 1 : 0.5;
        int left = (int) (middle - offset), right = (int) (middle + offset);
        pair<unsigned long, unsigned long> result = {0, 0};

        while (left >= 0 && right < s.length()) {
            if (s[left] == s[right]) {
                result = {left, right};
                left--;
                right++;
            } else {
                break;
            }
        }
        return result;
    }

    // 中轴扩展法（改进版）：
    // 时间复杂度:O(n^2) 空间复杂度:O(1)
    // Time: 3ms
    string longestPalindrome2(string s) {
        if (s.size() < 2)
            return s;
        unsigned long len = s.size(), max_left = 0, max_len = 1, left, right;
        for (unsigned long start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }

    // 最长公共子串法：
    // 找出字符串以及其翻转后的字符串中公共相等的最长的子字符串即可，但由于出现如下情况
    // S = "abacdfgdcaba" S'="abacdgfdcaba"的公共字符串abacd并不是回文串，因此每次找到一个公共子串时，需要判断是否回文。
    // 此处使用DP解决最长公共子串
    // 时间复杂度:O(n^2) 空间复杂度:O(n)
    // Time: 232ms
    string longestPalindrome3(string s) {
        string reverseString;
        reverseString.assign(s.rbegin(), s.rend());

        return getLongestCommonSubstring(s, reverseString);
    }

    string getLongestCommonSubstring(string s1, string s2) {
        int *last = new int[s1.length()]{0};
        string maxString = "";
        for (int i = 0; i < s1.length(); ++i) {
            int *current = new int[s2.length()]{0};
            for (int j = 0; j < s2.length(); ++j) {
                if (s1[i] == s2[j]) {
                    current[j] = 1 + (j == 0 ? 0 : last[j - 1]);
                    if (maxString.length() < current[j] && isPalindrome(
                            s2.substr((unsigned long) (j - current[j] + 1), (unsigned long) current[j]))) {
                        maxString = s2.substr((unsigned long) (j - current[j] + 1), (unsigned long) current[j]);
                    }
                }
            }
            last = current;
        }
        delete[] last;

        return maxString;
    };

    bool isPalindrome(string s) {
        unsigned long i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // 动态规划法：
    // 时间复杂度:O(n^2) 空间复杂度:O(n^2)
    // Time: 66ms
    string longestPalindrome4(string s) {
        int start = 0, maxLen = 1, n = (int) s.size();
        bool isPal[1000][1000] = {false};
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if ((i + 1 > j - 1 || isPal[i + 1][j - 1]) && s[i] == s[j]) {
                    isPal[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr((unsigned long) start, (unsigned long) maxLen);
    }

    // Manacher算法
    // 详情参见：http://articles.leetcode.com/longest-palindromic-substring-part-ii/
    // 时间复杂度:O(n) 空间复杂度:O(n)
    // Time: 6ms
    string longestPalindrome5(string s) {
        string T = prepare(s);

        vector<int> P(T.size(), 0); 
        int center = 0, boundary = 0, maxLen = 0, resCenter = 0;
        for (int i = 1; i < T.size() - 1; i++) {
            int iMirror = 2 * center - i;
            P[i] = (boundary > i) ? min(boundary - i, P[iMirror]) : 0;
            while (i - 1 - P[i] >= 0 && i + 1 + P[i] <= T.size() - 1 &&
                   T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
            if (i + P[i] > boundary) {
                center = i;
                boundary = i + P[i];
            }
            if (P[i] > maxLen) {
                maxLen = P[i];
                resCenter = i;
            }
        }
        return s.substr((unsigned long) ((resCenter - maxLen) / 2), (unsigned long) maxLen);
    }

    string prepare(string s) {
        string preStr = "";
        for (int i = 0; i < s.length(); ++i) {
            preStr += "#";
            preStr += s[i];
        }
        return preStr.length() > 0 ? preStr + "#" : "";
    }
};