// Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author: ML3426
// Date: 2017-06-21

/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty()) return NULL;

        int val = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(val);
        auto midIter = find(inorder.begin(), inorder.end(), val);
        vector<int> leftInVec = vector<int>(inorder.begin(), midIter);
        vector<int> rightInVec = vector<int>(midIter + 1, inorder.end());

        midIter = postorder.begin() + leftInVec.size();
        vector<int> leftPostVec = vector<int>(postorder.begin(), midIter);
        vector<int> rightPostVec = vector<int>(midIter, midIter + rightInVec.size());
        root->left = buildTree(leftInVec, leftPostVec);
        root->right = buildTree(rightInVec, rightPostVec);
        return root;
    }
};