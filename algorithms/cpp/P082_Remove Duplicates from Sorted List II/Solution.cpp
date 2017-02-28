// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author: ML3426
// Date: 2017-02-28

/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *first = new ListNode(0), *curr = first, *last;
        last = head;
        if (head != NULL) head = head->next;

        while (head != NULL) {
            if (head->val != last->val) {
                curr->next = last;
                curr = curr->next;
                curr->next = NULL;
                last = head;
                head = head->next;
            } else {
                while (head != NULL && head->val == last->val) head = head->next;
                last = head;
                if (head != NULL) head = head->next;
            }
        }

        if (last != NULL && last->val != curr->val) {
            last->next = NULL;
            curr->next = last;
        }

        return first->next;
    }
};
