// Source: https://leetcode.com/problems/wildcard-matching/
// Author: ML3426
// Date: 2017-02-15

/*
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
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
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力解法
    // 递归的进行匹配，针对('a'，'.'，'.*', 'a*')等多重情况处理，处理完再处理剩下的未匹配的部分。
    // Time: Time Limit Exceeded
    bool isMatch1(string s, string p) {
        if (s.length() == 0) {
            return p.find_first_not_of('*') == -1 || p.length() == 0;
        }

        if (p.length() == 0) return false;

        if (p[0] == '?') {
            return isMatch1(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
        }

        if (p[0] == '*') {
            unsigned long pos = p.find_first_not_of('*');
            if (pos == -1) pos = p.size();
            string lefted = p.substr(pos, p.length() - pos);
            for (int i = 0; i <= s.length(); ++i) {
                bool temp_result = isMatch1(s.substr((unsigned long) i, s.length() - i), lefted);
                if (temp_result) return true;
            }
        }

        return s[0] == p[0] ? isMatch1(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1)) : false;
    }

    // 动态规划解法
    // 时间复杂度为O(N^2)，空间复杂度为O(N^2)
    // Time：59ms
    bool isMatch2(string s, string p) {
        p = prepare(p);

        unsigned long m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = j == 1 || dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');

        return dp[m][n];
    }

    string prepare(string p) {
        if (p.size() == 0) return "";
        string res = "";
        res += p[0];

        for (int i = 1; i < p.size(); ++i) {
            if (p[i] == '*' && p[i - 1] == '*') continue;
            else res += p[i];
        }

        return res;
    }
};
