// Source: https://leetcode.com/problems/reverse-linked-list-ii/
// Author: ML3426
// Date: 2017-06-10

/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *first = new ListNode(0), *curr = first, *reversed;
        for (int i = 0; i < m; ++i) {
            if (curr->next != NULL) curr = curr->next; 
            curr->next = head;
            head = head->next;
        }
        if (curr->next != NULL) {
            reversed = curr->next;
            curr->next->next = NULL;
            for (int i = 0; i < n - m; ++i) {
                ListNode *next = curr->next;
                curr->next = head;
                swap(head->next, next);
                head = next;
            }
            reversed->next = head;
        }
        return first->next;
    }
};