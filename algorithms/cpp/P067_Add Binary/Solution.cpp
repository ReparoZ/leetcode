// Source: https://leetcode.com/problems/add-binary/
// Author: ML3426
// Date: 2017-02-21

/*
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 时间复杂度为O(MAX(M, N))，空间复杂度为O(1)
    // Time: 3ms
    string addBinary(string a, string b) {
        if (a.length() < b.length()) return addBinary(b, a);
        bool carry = false;
        int aPos = (int) a.length() - 1, bPos = (int) b.length() - 1;
        string res;

        while (aPos >= 0 || bPos >= 0) {
            int aBit = aPos < 0 ? 0 : a[aPos] - '0';
            int bBit = bPos < 0 ? 0 : b[bPos] - '0';
            int cBit = carry ? 1 : 0;
            res.insert(res.begin(), char ('0' + ((aBit + bBit + cBit) & 1)));
            carry = (aBit + bBit + cBit > 1);
            aPos--; bPos--;
        }
        
        if (carry) res.insert(res.begin(), '1');
        return res;
    }
};