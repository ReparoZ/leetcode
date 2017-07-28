// Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: ML3426
// Date: 2017-07-28

/*
 * Given a binary tree
 * 
 *     struct TreeLinkNode {
 *       TreeLinkNode *left;
 *       TreeLinkNode *right;
 *       TreeLinkNode *next;
 *     }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * Note:
 * 
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 * For example,
 * Given the following perfect binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
 */

#include <iostream>
#include <queue>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    explicit TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

using namespace std;

class Solution {
public:
    // 分层连接处理
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 19ms
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> layer{root};
        if (root == nullptr) return;

        while (!layer.empty()) {
            vector<TreeLinkNode *> currentLayer;
            TreeLinkNode *last = nullptr;
            for (int i = 0; i < layer.size(); last = layer[i], ++i) {
                if (last != nullptr) last->next = layer[i];
                if (layer[i]->left != nullptr) {
                    currentLayer.push_back(layer[i]->left);
                    currentLayer.push_back(layer[i]->right);
                }
            }
            layer = currentLayer;
        }
    }
};