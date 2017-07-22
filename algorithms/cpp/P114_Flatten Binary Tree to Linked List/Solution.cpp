// Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: ML3426
// Date: 2017-07-22

/*
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example,
 * Given
 * 
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 使用递归的方法，每次取出根节点，然后将左右子树flatten
    // 再在根节点的右子树拼接上flatten后的左右子树
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        
        auto left = root->left;
        auto right = root->right;
        
        flatten(left);
        flatten(right);
        
        root->left = nullptr;
        if (left != nullptr) {
            root->right = left;
            while (left->right != nullptr) left = left->right;
            left->right = right;
        } else {
            root->right = right;
        }
    }
};