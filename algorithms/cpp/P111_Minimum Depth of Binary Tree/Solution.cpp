// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author: ML3426
// Date: 2017-07-08

/*
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    // 利用递归，查看左右两边到叶子节点的最小深度
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 6ms
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int leftMin = minDepth(root->left);
        int rightMin = minDepth(root->right);
        if (leftMin == 0 && rightMin == 0)
            return 1;
        if (leftMin == 0)
            leftMin = INT_MAX;
        if (rightMin == 0)
            rightMin = INT_MAX;
        return min(leftMin, rightMin) + 1;
    }
};
