// Source: https://leetcode.com/problems/combination-sum-ii/
// Author: ML3426
// Date: 2017-02-13

/*
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    // 直接利用了乘法和加法的规则进行竖式乘法
    // 时间复杂度为O(NM)，空间复杂度为O(1)
    // Time: 23ms
    string multiply(string num1, string num2) {
        string res = "0";

        for (auto i = num1.begin(); i != num1.end(); ++i) {
            string mulRes = multiply(*i, num2);
            if (res != "0") res += "0";
            res = add(res, mulRes);
        }

        return res;
    }

    string multiply(char digit, string num) {
        int digitNum = digit - '0';
        int carry = 0;
        string res;

        for (auto i = num.rbegin(); i != num.rend(); ++i) {
            int currentDigit = *i - '0';
            int tempRes = currentDigit * digitNum + carry;
            carry = tempRes / 10;
            res.insert(0, 1, char(tempRes % 10 + '0'));
        }

        if (carry != 0) res.insert(0, 1, char(carry + '0'));
        auto pos = res.find_first_not_of('0');

        return pos == -1 ? "0" : res.substr(pos, res.size() - pos);
    }

    string add(string num1, string num2) {
        if (num1.size() < num2.size()) return add(num2, num1);
        int carry = 0;
        string res;

        for (auto i = num1.rbegin(), j = num2.rbegin(); i != num1.rend(); ++i) {
            int sum = (*i - '0') + (j == num2.rend() ? 0 : (*j - '0')) + carry;
            carry = sum / 10;
            res.insert(0, 1, char(sum % 10 + '0'));
            if (j != num2.rend()) j++;
        }

        if (carry != 0) res.insert(0, 1, char(carry + '0'));
        auto pos = res.find_first_not_of('0');

        return pos == -1 ? "0" : res.substr(pos, res.size() - pos);
    }
};