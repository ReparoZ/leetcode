// Source: https://leetcode.com/problems/add-two-numbers/
// Author: ML3426
// Date: 2017-01-16

/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in 
 * reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    // 各位相加，进位+1，注意当两个List遍历完之后还有可能有进位，如5+5=10。
    // 时间复杂度为O(MAX(m, n))，空间复杂度为O(MAX(m, n))
    // Time: 32 ms
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0), *tail = head;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
            ListNode *nextNode = new ListNode(sum % 10);
            carry = sum / 10;
            tail->next = nextNode;
            tail = nextNode;
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }
        return head->next;
    }
};