// Source: https://leetcode.com/problems/unique-binary-search-trees/
// Author: ML3426
// Date: 2017-06-11

/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 迭代法
    // 以这个结点为根的可行二叉树数量就是左右子树可行二叉树数量的乘积，所以总的数量是将以所有结点为根的可行结果累加起来。
    // 时间复杂度为O(N^2)，空间复杂度为O(N)
    // 其实此数列就是卡塔兰数数列
    // Time: 0ms
    int numTrees(int n) {
        int res[n + 1];
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int ans = 0;
            for (int j = 0; j < i; ++j) {
                ans += res[j] * res[i - j - 1];
            }
            res[i] = ans;
        }
        return res[n];
    }
};