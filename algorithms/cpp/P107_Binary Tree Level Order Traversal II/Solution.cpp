// Source: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author: ML3426
// Date: 2017-06-21

/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
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
    // 一层一层的循环，收集中间结果保存，与P102一样，只是改变了插入的方式
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 9ms
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode *> last;

        if (root != NULL) last.push_back(root);
        while (!last.empty()) {
            vector<TreeNode *> current;
            vector<int> currentRes;
            for (int i = 0; i < last.size(); ++i) {
                currentRes.push_back(last[i]->val);
                if (last[i]->left != NULL) current.push_back(last[i]->left);
                if (last[i]->right != NULL) current.push_back(last[i]->right);
            }
            res.insert(res.begin(), currentRes);
            last = current;
        }
        return res;
    }
};