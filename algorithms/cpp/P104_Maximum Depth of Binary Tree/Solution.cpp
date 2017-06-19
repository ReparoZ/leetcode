// Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author: ML3426
// Date: 2017-06-19

/*
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    // 一层一层遍历，保存到每一层的结点
    // 每向下遍历一层，则将计数器加一
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 6ms
    int maxDepth(TreeNode *root) {
        vector<TreeNode *> layer;
        int layerNum = 0;

        if (root != NULL) {
            layer.push_back(root);
        }
        while (!layer.empty()) {
            vector<TreeNode *> current;
            for (int i = 0; i < layer.size(); ++i) {
                if (layer[i]->left != NULL) current.push_back(layer[i]->left);
                if (layer[i]->right != NULL) current.push_back(layer[i]->right);
            }
            layer = current;
            ++layerNum;
        }

        return layerNum;
    }
};