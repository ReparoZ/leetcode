// Source: https://leetcode.com/problems/recover-binary-search-tree/
// Author: ML3426
// Date: 2017-06-17

/*
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    // 当第一次找到逆序时，如43，把p=3，q=4，如果后面没有发现第二个逆序，那么最后交换p和q即可。如果有两个逆序，如63和52，当我们发现第一个逆序63时，把p=6，q=3，然后发现第二个逆序52时，把q=2，最后交换p和q。
    // 时间复杂度O(N)，空间复杂度O(1)
    // Time: 22ms
    void recoverTree(TreeNode *root) {
        TreeNode *errorNode1 = NULL, *errorNode2 = NULL;
        TreeNode *lastNode = NULL;
        stack<TreeNode *> stk;

        while (root != NULL || !stk.empty()) {
            while (root != NULL) {
                stk.push(root);
                root = root->left;
            }

            TreeNode *top = stk.top();
            stk.pop();
            if (lastNode == NULL) lastNode = top;
            else if (lastNode->val > top->val) {
                if (errorNode1 == NULL) {
                    errorNode1 = lastNode;
                    errorNode2 = top;
                } else {
                    swap(errorNode1->val, top->val);
                    errorNode1 = NULL;
                    errorNode2 = NULL;
                    break;
                }
            }
            lastNode = top;
            root = top->right;
        }

        if (errorNode1 != NULL && errorNode2 != NULL) {
            swap(errorNode1->val, errorNode2->val);
        }
    }
};