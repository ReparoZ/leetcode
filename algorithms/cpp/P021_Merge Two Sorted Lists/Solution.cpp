// Source: https://leetcode.com/problems/merge-two-sorted-lists/
// Author: ML3426
// Date: 2017-02-09

/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 合并时注意两个指针的移动和NULL的判定就行
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0), *current = head;

        while (l1 != NULL || l2 != NULL) {

            if (l1 == NULL) {
                current->next = l2;
                l2 = NULL;
            } else if (l2 == NULL) {
                current->next = l1;
                l1 = NULL;
            } else if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
                current = current->next;
            } else {
                current->next = l2;
                l2 = l2->next;
                current = current->next;
            }
        }

        return head->next;
    }
};