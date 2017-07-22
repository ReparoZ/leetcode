// Source: https://leetcode.com/problems/distinct-subsequences/
// Author: ML3426
// Date: 2017-07-22

/*
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * 
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * 
 * Return 3.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // DP法
    // 创建一个t.length()+1行，s.length()的二维数组
    // 当t[i - 1] == s[j - 1] && dp[i - 1][j - 1] > 0时，当前的dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
    // 否则等于dp[i][j - 1]
    // 时间复杂度为O(MN)，空间复杂度为O(MN)
    // Time: 6ms
    int numDistinct(string s, string t) {
        auto row = t.length(), col = s.length();

        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        dp[0] = vector<int>(col + 1, 1);
        for (int i = 1; i < row + 1; ++i) {
            for (int j = 1; j < col + 1; ++j) {
                if (t[i - 1] == s[j - 1] && dp[i - 1][j - 1] > 0) {
                    auto sum = dp[i - 1][j - 1] + dp[i][j - 1];
                    dp[i][j] = sum > 1 ? sum : 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        
        return dp[row][col];
    }
};