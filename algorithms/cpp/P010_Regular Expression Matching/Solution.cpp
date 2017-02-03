// Source: https://leetcode.com/problems/regular-expression-matching/
// Author: ML3426
// Date: 2017-02-02

/*
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力解法
    // 递归的进行匹配，针对('a'，'.'，'.*', 'a*')等多重情况处理，处理完再处理剩下的未匹配的部分。
    // 时间复杂度最好为N(1)，最差为数量级，空间复杂度为O(1）
    // Time：89ms
    bool isMatch1(string s, string p) {
        if (s.length() == 0 && (p.length() < 2 || p[1] != '*')) {
            return p.length() == 0;
        } else if (p.length() == 0) {
            return false;
        }

        if (p.length() > 1 && p[1] == '*') {
            for (int i = 0; i <= s.length(); ++i) {
                bool temp_result = isMatch1(s.substr((unsigned long) i, s.length() - i), p.substr(2, p.length() - 2));
                if (temp_result) return true;

                if (p[0] != '.' && s[i] != p[0]) break;
            }
            return false;
        } else if (p[0] == '.') {
            return isMatch1(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
        } else {
            return s[0] == p[0] ? isMatch1(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1)) : false;
        }
    }

    // 动态规划解法
    // https://discuss.leetcode.com/topic/17852/9-lines-16ms-c-dp-solutions-with-explanations
    // 时间复杂度为O(N^2)，空间复杂度为O(N^2)
    // Time：6ms
    bool isMatch2(string s, string p) {
        unsigned long m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};