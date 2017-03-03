// Source: https://leetcode.com/problems/scramble-string/
// Author: ML3426
// Date: 2017-03-02

/*
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 *     great
 *    /    \
 *   gr    eat
 *  / \    /  \
 * g   r  e   at
 *            / \
 *           a   t
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 * 
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 * 
 *     rgeat
 *    /    \
 *   rg    eat
 *  / \    /  \
 * r   g  e   at
 *            / \
 *           a   t
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 * 
 *     rgtae
 *    /    \
 *   rg    tae
 *  / \    /  \
 * r   g  ta  e
 *        / \
 *       t   a
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 解释见https://discuss.leetcode.com/topic/20094/my-c-solutions-recursion-with-cache-dp-recursion-with-cache-and-pruning-with-explanation-4ms/2
    // 时间复杂度为O(N^3)，空间复杂度为O(N^3)
    // Time: 19ms
    bool isScramble(string s1, string s2) {
        auto sSize = s1.size();

        if (0 == sSize) return true;
        if (1 == sSize) return s1 == s2;
        bool isScrambleDp[sSize + 1][sSize][sSize]{false};

        for (int i = 0; i < sSize; ++i)
            for (int j = 0; j < sSize; ++j)
                isScrambleDp[1][i][j] = s1[i] == s2[j];

        for (int len = 2; len <= sSize; ++len)
            for (int i = 0; i <= sSize - len; ++i)
                for (int j = 0; j <= sSize - len; ++j)
                    for (int k = 1; k < len && !isScrambleDp[len][i][j]; ++k) {
                        isScrambleDp[len][i][j] =
                                isScrambleDp[len][i][j] ||
                                (isScrambleDp[k][i][j] && isScrambleDp[len - k][i + k][j + k]);
                        isScrambleDp[len][i][j] =
                                isScrambleDp[len][i][j] ||
                                (isScrambleDp[k][i + len - k][j] && isScrambleDp[len - k][i][j + k]);
                    }

        return isScrambleDp[sSize][0][0];
    }
};