// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author: ML3426
// Date: 2017-02-28

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *first = new ListNode(0), *curr = first;
        curr = (curr->next = head);
        if (head != NULL) head = head->next;

        while (head != NULL) {
            if (head->val != curr->val) curr = (curr->next = head);
            head = head->next;
        }
        if (curr != NULL) curr->next = NULL;

        return first->next;
    }
};