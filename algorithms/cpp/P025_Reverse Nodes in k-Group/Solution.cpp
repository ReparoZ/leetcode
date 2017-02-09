// Source: https://leetcode.com/problems/reverse-nodes-in-k-group
// Author: ML3426
// Date: 2017-02-09

/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * 
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
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
    // 先计算出长度，再拼接出一个新的链表，新的链表按照k的大小反向拼接，如
    // [head->1]、[head->2->1]、[head->3->2->1]
    // 每拼接完一组移动head的位置
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 23ms
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *first = new ListNode(0), *current = first;
        first->next = head;

        int listSize = 0, round;
        while (head != NULL) listSize++, head = head->next;
        round = listSize / k;
        head = first->next;

        for (int i = 0; i < round; ++i) {
            ListNode *node = head;
            for (int j = 0; j < k; ++j) {
                ListNode *next = head->next;
                head->next = current->next;
                current->next = head;
                head = next;
            }
            current = node;
        }

        current->next = head;
        return first->next;
    }
};