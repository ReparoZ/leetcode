// Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author: ML3426
// Date: 2017-07-01

/*
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 与P108的思路完全相同，只是一个是数组，一个是链表
    // 时间复杂度为O(NLOGN)，空间复杂度为O(1)
    // Time: 22ms
    TreeNode *sortedListToBST(ListNode *head) {
        int size = 0;
        ListNode *current = head;
        while (current != NULL) { current = current->next; ++size; }
        return sortedListToBST(head, size);
    }

    TreeNode *sortedListToBST(ListNode *head, int size) {
        switch (size) {
            case 0: return NULL;
            case 1: return new TreeNode(head->val);
            default: {
                int middle = size / 2;
                ListNode *current = head;
                for (int i = 0; i < middle; ++i) { current = current->next; }
                TreeNode *root = new TreeNode(current->val);
                root->left = sortedListToBST(head, middle);
                root->right = sortedListToBST(current->next, size - middle - 1);
                return root;
            }
        };
    }
};