// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: ML3426
// Date: 2017-02-08

/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    // 给链表加一个新的头结点，使用两个指针指向结点，让这个两个指针差距n个结点，这样当后面的结点到链表尾部时，
    // 前一个结点搞好到达了要删除的结点的前一个节点
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *begin = new ListNode(0); begin->next = head;
        ListNode *front = begin, *back = begin;

        for (int i = 0; i <= n; ++i) {
            back = back->next;
        }

        while (back != NULL) {
            front = front->next;
            back = back->next;
        }

        front->next = front->next->next;

        return begin->next;
    }
};
