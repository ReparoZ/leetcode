// Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: ML3426
// Date: 2017-07-29

/**
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 */

#include <iostream>
#include <vector>

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
    // Time: 26ms
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
              }
              if (layer[i]->right != nullptr) {
                  currentLayer.push_back(layer[i]->right);
              }
          }
          layer = currentLayer;
      }
    }
};
