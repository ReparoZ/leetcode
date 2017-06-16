// Source: https://leetcode.com/problems/validate-binary-search-tree/
// Author: ML3426
// Date: 2017-06-16

/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * Example 1:
 *     2
 *    / \
 *   1   3
 * Binary tree [2,1,3], return true.
 * Example 2:
 *     1
 *    / \
 *   2   3
 * Binary tree [1,2,3], return false.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 二叉树的中序遍历，中序的遍历顺序必须是递增的
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 9ms
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        
        while (root != NULL || !stk.empty()) {
            while (root != NULL) {
                stk.push(root);
                root = root->left;
            }
            
            TreeNode *top = stk.top();
            stk.pop();
            if (res.empty()) res.push_back(top->val);
            else if (top->val <= res[res.size() - 1]) return false;
            else res.push_back(top->val);
            root = top->right;
        }
        
        return true;
    }
};