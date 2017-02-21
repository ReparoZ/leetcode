// Source: https://leetcode.com/problems/plus-one/
// Author: ML3426
// Date: 2017-02-21

/*
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 简单的加法
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 3ms
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        for (int i = (int) (digits.size() - 1); i >= 0 && carry; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i]++;
                carry = false;
            }
        }

        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};