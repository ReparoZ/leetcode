// Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: ML3426
// Date: 2017-06-10

/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    // 简单的非迭代中序遍历算法
    // Time: 3ms
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> nodeStack;
        vector<int> res;
        if (root == NULL) return res;
        bool isLeftTraveled = false;
        
        nodeStack.push(root);
        while (nodeStack.size() != 0) {
            if (root->left != NULL && !isLeftTraveled) {
                root = root->left;
                nodeStack.push(root);
                isLeftTraveled = false;
            } else {
                TreeNode *top = nodeStack.top();
                nodeStack.pop();
                res.push_back(top->val);
                root = top;
                isLeftTraveled = true;
                if (root->right != NULL) {
                    isLeftTraveled = false;
                    root = root->right;
                    nodeStack.push(root);
                }
            }
        }
        return res;
    }
};