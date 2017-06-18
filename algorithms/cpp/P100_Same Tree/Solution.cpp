// Source: https://leetcode.com/problems/same-tree/
// Author: ML3426
// Date: 2017-06-18

/*
 * Given two binary trees, write a function to check if they are equal or not.
 * 
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    // 简单的递归判断两棵树结点
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 3ms
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if (p != NULL && q != NULL && p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }
};