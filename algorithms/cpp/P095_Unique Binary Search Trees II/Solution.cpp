// Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author: ML3426
// Date: 2017-06-11

/*
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
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
    // Time: 19ms
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int begin, int end) {
        vector<TreeNode *> ret;
        
        if (begin > end) ret.push_back(NULL);
        else if (begin == end) {
            TreeNode *node = new TreeNode(begin);
            ret.push_back(node);
        } else {
            for (int i = begin; i <= end; i++) {
                vector<TreeNode *> left = generateTrees(begin, i - 1);
                vector<TreeNode *> right = generateTrees(i + 1, end);
                for (int l = 0; l < left.size(); l++) {
                    for (int r = 0; r < right.size(); r++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left[l];
                        root->right = right[r];
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
};