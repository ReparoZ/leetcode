// Source: https://leetcode.com/problems/simplify-path/
// Author: ML3426
// Date: 2017-02-25

/*
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 动态规划法计算字符串的编辑距离
    // 由于一个字符串只有插入删除替换三种操作，因此如果说dp[i][j]是word1和word2之间的编辑距离
    // 则dp[i][j] = min((word1[i - 1] == word2[j - 1] ? leftUp : leftUp + 1), min(left + 1, up + 1));
    // leftUp为左上角的dp[i - 1][j - 1]，left为左方dp[i][j - 1]的值, up为右方dp[i - 1][j]的值
    // 时间复杂度为O(N^2)，空间复杂度为O(N^2)
    // Time: 12ms
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1));
        for (int i = 0; i < dp[0].size(); ++i) dp[0][i] = i;
        for (int i = 0; i < dp.size(); ++i) dp[i][0] = i;

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                int leftUp = dp[i - 1][j - 1], left = dp[i][j - 1], up = dp[i - 1][j];
                dp[i][j] = min((word1[i - 1] == word2[j - 1] ? leftUp : leftUp + 1), min(left + 1, up + 1));
            }
        }

        return dp[word1.size()][word2.size()];
    }
};