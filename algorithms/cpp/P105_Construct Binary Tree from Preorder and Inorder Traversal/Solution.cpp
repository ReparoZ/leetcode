// Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author: ML3426
// Date: 2017-06-21

/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    // 迭代每次将根节点和左子树右子树的序列拆开
    // 时间复杂度为O(LOGN)，空间复杂度为O(N)
    // Time: 42ms
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return NULL;

        int val = preorder[0];
        TreeNode *root = new TreeNode(val);
        auto midIter = find(inorder.begin(), inorder.end(), val);
        vector<int> leftInVec = vector<int>(inorder.begin(), midIter);
        vector<int> rightInVec = vector<int>(midIter + 1, inorder.end());
        
        midIter = preorder.begin() + 1 + leftInVec.size();
        vector<int> leftPreVec = vector<int>(preorder.begin() + 1, midIter);
        vector<int> rightPreVec = vector<int>(midIter, preorder.end());
        root->left = buildTree(leftPreVec, leftInVec);
        root->right = buildTree(rightPreVec, rightInVec);
        return root;
    }
};