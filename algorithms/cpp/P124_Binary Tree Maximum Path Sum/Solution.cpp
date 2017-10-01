// Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Author: ML3426
// Date: 2017-09-30

/**
 * Given a binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
 * 
 * For example:
 * Given the below binary tree,
 * 
 *        1
 *       / \
 *      2   3
 * Return 6.
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 用深度遍历的方法进行递归，用maxSum来代表到目前为止的最大值，left，right表示只有左右分支的情况下的最大值
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 19ms
    int maxPathSum(TreeNode *root) {
        int res = root->val;
        maxPathSumDFS(root, res);
        return res;
    }

    int maxPathSumDFS(TreeNode *root, int &maxSum) {
        if (!root) return 0;
        int left = maxPathSumDFS(root->left, maxSum);
        int right = maxPathSumDFS(root->right, maxSum);
        int currentMax = root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0);
        maxSum = max(maxSum, currentMax);
        return max(left, right) > 0 ? max(left, right) + root->val : root->val;
    }
};