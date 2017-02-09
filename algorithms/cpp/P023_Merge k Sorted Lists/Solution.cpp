// Source: https://leetcode.com/problems/merge-k-sorted-lists/
// Author: ML3426
// Date: 2017-02-09

/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 分治法，每次将list二分，直到将问题转化为P21的mergeTwoLists，再合并成一个链表即可
    // 时间复杂度为O(NKlogK)，空间复杂度为O(1)
    // Time: 29ms
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) {
            return lists[0];
        }

        auto mid = lists.size() / 2;
        auto left = vector<ListNode *>(lists.begin(), lists.begin() + mid);
        auto right = vector<ListNode *>(lists.begin() + mid, lists.end());

        return mergeTwoLists(mergeKLists(left), mergeKLists(right));
    }

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