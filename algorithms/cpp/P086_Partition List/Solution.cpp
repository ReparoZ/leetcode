// Source: https://leetcode.com/problems/partition-list/
// Author: ML3426
// Date: 2017-03-02

/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    // 用左右两个指针分别保存两部分的结点，最后再拼接成一个链表。
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    ListNode *partition(ListNode *head, int x) {
        ListNode *leftHead = new ListNode(0), *left = leftHead, *rightHead = new ListNode(0), *right = rightHead;

        while (head != NULL) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }

            head = head->next;
        }

        right->next = NULL;
        left->next = rightHead->next;

        return leftHead->next;
    }
};