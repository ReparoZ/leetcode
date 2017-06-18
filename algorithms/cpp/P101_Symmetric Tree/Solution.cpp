// Source: https://leetcode.com/problems/symmetric-tree/
// Author: ML3426
// Date: 2017-06-18

/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */

#include <iostream>
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
    // 迭代法
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 3ms
    bool isSymmetric1(TreeNode *root) {
        return root == NULL ? true: isSymmetric1(root->left, root->right);
    }

    bool isSymmetric1(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) return true;
        else if (left != NULL && right != NULL && left->val == right->val)
            return isSymmetric1(left->right, right->left) && isSymmetric1(left->left, right->right);
        else return false;
    }
    
    // 非迭代法
    // 利用一个栈来保存镜像的两个结点，再来判断是否相等
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 3ms
    bool isSymmetric2(TreeNode *root) {
        if (root == NULL) return true;
        stack<pair<TreeNode *, TreeNode *>> stk;
        stk.push({root->left, root->right});
        while (!stk.empty()) {
            TreeNode *firstElem = stk.top().first;
            TreeNode *secondElem = stk.top().second;
            stk.pop();
            if (firstElem == NULL && secondElem == NULL) continue;
            else if (firstElem != NULL && secondElem != NULL && firstElem->val == secondElem->val) {
                stk.push({firstElem->left, secondElem->right});
                stk.push({firstElem->right, secondElem->left});
            } else return false;
        }
        
        return true;
    }
};