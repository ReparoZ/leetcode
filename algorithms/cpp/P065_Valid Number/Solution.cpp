// Source: https://leetcode.com/problems/valid-number/
// Author: ML3426
// Date: 2017-02-21

/*
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 */
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
    // 先获取整数，小数，指数部分，去掉正负号，然后查看每个部分是不是为空，且是不是只包含数字字符
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 6ms
    bool isNumber(string s) {
        // Trim Data
        s.erase(s.find_last_not_of(' ') + 1);
        s.erase(0, s.find_first_not_of(' '));
        // Initial Variable
        unsigned long ePos = s.size(), dotPos = s.size(), sum = 0;
        string integer, fractional, base, index;
        // Split E
        if ((ePos = s.find_first_of('e')) != -1 || (ePos = s.find_first_of('E')) != -1) {
            index = s.substr(ePos + 1, s.size() - ePos);
            // Remove + - Symbol
            if (index[0] == '+' || index[0] == '-') index.erase(0, 1);
            // If has e but no other char without + -
            if (index.size() == 0) return false;
        }
        // Get Base
        base = s.substr(0, ePos);
        // Get fractional
        if ((dotPos = base.find_first_of('.')) != -1) {
            fractional = base.substr(dotPos + 1, base.size() - dotPos);
        }
        // Get integer
        integer = base.substr(0, dotPos);
        // Remove + - Symbol
        if (integer[0] == '+' || integer[0] == '-') integer.erase(0, 1);
        // If only has e but no other char without + -
        if (integer.size() + fractional.size() == 0) return false;
        string numbers[]{integer, fractional, index};
        for (string number : numbers) {
            sum += number.size();
            for (auto item : number) {
                if (!isdigit(item)) return false;
            }
        }
        return true;
    }
};