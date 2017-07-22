// Source: https://leetcode.com/problems/path-sum-ii/
// Author: ML3426
// Date: 2017-07-15

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
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
    // Time: 25ms
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        return pathSum(root, sum, {});
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum, vector<int> before) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        else if (root->left == NULL && root->right == NULL && root->val == sum) {
            before.push_back(root->val);
            result.push_back(before);
            return result;
        } else {
            vector<int> left(before), right(before);
            left.push_back(root->val);
            right.push_back(root->val);
            vector<vector<int>> leftRes = pathSum(root->left, sum - root->val, left);
            vector<vector<int>> rightRes = pathSum(root->right, sum - root->val, right);
            result.insert(result.end(), leftRes.begin(), leftRes.end());
            result.insert(result.end(), rightRes.begin(), rightRes.end());
            return result;
        }
    }
};