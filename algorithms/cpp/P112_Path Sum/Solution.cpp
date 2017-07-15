// Source: https://leetcode.com/problems/path-sum/
// Author: ML3426
// Date: 2017-07-15

/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 利用迭代法，查看左右子树是不是能求到sum减去当前节点的值
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        else if (root->left == NULL && root->right == NULL && root->val == sum) return true;
        else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};