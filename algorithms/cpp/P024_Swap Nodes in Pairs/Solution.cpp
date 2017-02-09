// Source: https://leetcode.com/problems/swap-nodes-in-pairs/
// Author: ML3426
// Date: 2017-02-09

/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    // 简单的交换指针的指向，但是要注意交换的顺序以及结果
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 3ms
    ListNode *swapPairs(ListNode *head) {
        ListNode *first = new ListNode(0), *current = first;
        first->next = head;

        while (current != NULL && current->next != NULL && current->next->next != NULL) {
            ListNode *cNext = current->next, *nNext = current->next->next;
            current->next = nNext;
            cNext->next = nNext->next;
            nNext->next = cNext;
            current = cNext;
        }

        return first->next;
    }
};