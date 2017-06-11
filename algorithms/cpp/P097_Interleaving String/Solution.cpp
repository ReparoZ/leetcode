// Source: https://leetcode.com/problems/interleaving-string/
// Author: ML3426
// Date: 2017-06-11

/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // DP法
    // 时间复杂度为O(N^2)，空间复杂度为O(N^2)
    // Time: 6ms
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;

        bool dp[s2.length() + 1][s1.length() + 1];
        dp[0][0] = true;
        for (int j = 1; j <= s1.length(); j++) {
            dp[0][j] = dp[0][j - 1] && (s1[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= s2.length(); i++) {
            dp[i][0] = dp[i - 1][0] && (s2[i - 1] == s3[i - 1]);
        }

        for (int i = 1; i <= s2.length(); i++) {
            for (int j = 1; j <= s1.length(); j++) {
                dp[i][j] = dp[i - 1][j] && (s2[i - 1] == s3[i + j - 1])
                           || dp[i][j - 1] && (s1[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[s2.length()][s1.length()];
    }
};