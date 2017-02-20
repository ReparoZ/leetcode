// Source: https://leetcode.com/problems/rotate-list/
// Author: ML3426
// Date: 2017-02-19

/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    // 创造首结点，计算链表大小，位移元素
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        ListNode *first = new ListNode(0), *curr = first, *right = head;
        first->next = head;
        k %= listSize(head);

        for (int i = 0; i <= k && right != NULL; ++i) right = right->next;
        while (right != NULL) right = right->next, head = head->next;
        while (head != NULL && head->next != NULL) {
            ListNode *next = head->next;
            head->next = next->next;
            next->next = curr->next;
            curr->next = next;
            curr = curr->next;
        }

        return first->next;
    }

    int listSize(ListNode *head) {
        int size = 0;
        while (head != NULL) {
            ++size;
            head = head->next;
        }
        return size;
    }
};