// Source: https://leetcode.com/problems/string-to-integer-atoi/
// Author: ML3426
// Date: 2017-02-01

/*
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 * 
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 同P007的方法1，使用一个更大的类型来存储翻转的结果，最后如果相加的结果大于原类型的边界则单独处理
    // 此方法成立的前提是一定是要有一个比原类型大的类型
    // 时间复杂度：O(N)，空间复杂度O(N)。N为x的位数。
    // Time: 20ms
    int myAtoi(string str) {
        long result = 0;
        str = trim(str);
        bool isNeg = (str[0] == '-');
        for (int i = 0; i < str.length(); ++i) {
            if (i == 0 && (str[i] == '+' || str[i] == '-')) continue;
            if (!isdigit(str[i])) break;
            result = result * 10 + (str[i] - '0');
            if (isNeg && -result <= INT_MIN) return INT_MIN;
            if (!isNeg && result >= INT_MAX) return INT_MAX;
        }
        return (int) (isNeg ? -result : result);
    }
    
    // 同P007的方法2，在每一次相加之前判断结果将会不会超出原类型的边界。
    // 时间复杂度：O(N)，空间复杂度O(N)。N为x的位数。
    // Time: 25ms
    int myAtoi2(string str) {
        str = trim(str);
        if (str == "-2147483648") {
            return INT_MIN;
        }

        int offset = 0, result = 0;
        bool isNeg = false;
        if (str[offset] == '-') {
            isNeg = true;
            ++offset;
        } else if (str[offset] == '+') {
            ++offset;
        }

        for (int i = offset; i < str.length(); ++i) {
            if (!isdigit(str[i])) {
                break;
            }

            int digit = str[i] - '0';
            if ((isNeg && -result >= INT_MIN / 10 && INT_MIN + result * 10 + digit <= 0) ||
                (result <= INT_MAX / 10 && INT_MAX - result * 10 - digit >= 0)) {
                result = result * 10 + digit;
            } else {
                return isNeg ? INT_MIN : INT_MAX;
            }
        }

        return isNeg ? -result : result;
    }

    string trim(string s) {
        if (s.empty()) {
            return s;
        }

        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }
};