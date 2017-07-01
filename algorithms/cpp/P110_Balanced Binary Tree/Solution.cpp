// Source: https://leetcode.com/problems/balanced-binary-tree/
// Author: ML3426
// Date: 2017-07-01

/*
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    class Solution {
    public:
        // 迭代计算左右子树的深度，当深度绝对值大于1时返回-1，并将-1作为一个标志值
        // 时间复杂度为O(N)，空间复杂度为O(1)
        // Time: 9ms
        bool isBalanced(TreeNode *root) {
            return getDepth(root) != -1;
        }
        
        int getDepth(TreeNode *root) {
            if (root == NULL) return 0;
            else {
                int leftDepth = getDepth(root->left);
                if (leftDepth == -1) return -1;
                int rightDepth = getDepth(root->right);
                if (rightDepth == -1) return -1;
                if (abs(leftDepth - rightDepth) > 1) return -1;
                else return max(leftDepth, rightDepth) + 1;
            }
        } 
    };
};