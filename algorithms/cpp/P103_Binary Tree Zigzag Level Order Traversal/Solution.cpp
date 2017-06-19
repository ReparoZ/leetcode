// Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author: ML3426
// Date: 2017-06-19

/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
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
    // 一层一层的循环，收集中间结果保存，利用一个bool变量来决定是否是顺序还是逆序
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 3ms
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        vector<TreeNode *> last;
        bool zigZag = true;

        if (root != NULL) last.push_back(root);
        while (!last.empty()) {
            vector<TreeNode *> current;
            vector<int> currentRes;
            if (zigZag) {
                for (int i = 0; i < last.size(); ++i) {
                    currentRes.push_back(last[i]->val);
                    if (last[i]->left != NULL) current.push_back(last[i]->left);
                    if (last[i]->right != NULL) current.push_back(last[i]->right);
                }
            } else {
                for (int i = (int) (last.size() - 1); i >= 0; --i) {
                    currentRes.push_back(last[i]->val);
                    if (last[i]->right != NULL) current.insert(current.begin(), last[i]->right);
                    if (last[i]->left != NULL) current.insert(current.begin(), last[i]->left);
                }
            }
            res.push_back(currentRes);
            last = current;
            zigZag = !zigZag;
        }
        return res;
    }
};