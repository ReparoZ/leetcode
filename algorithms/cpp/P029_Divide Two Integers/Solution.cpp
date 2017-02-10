// Source: https://leetcode.com/problems/divide-two-integers/
// Author: ML3426
// Date: 2017-02-10

/*
 * Divide two integers without using multiplication, division and mod operator.
 * 
 * If it is overflow, return MAX_INT.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 注意的地方：1.边界值的判定，特别是INT_MAX这个特殊的值
    // 当大数/小数时，循环太久，将问题转化为dividend = divisor * (2 ^ a) + divisor * (2 ^ b) + divisor * (2 ^ c) + ... + divisor * (2 ^ z) + 余数
    // 的形式会快很多，结果则为(2 ^ a)+(2 ^ b)+(2 ^ c)+...+(2 ^ d)
    // 时间复杂度为O(?)，空间复杂度为O(1)
    // Time: 16ms
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (divisor == 1) return dividend;
        int result = 0;
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
            dividend += abs(divisor);
            result++;
        }
        if (divisor == INT_MIN) return result;
        bool flag = dividend < 0 ^divisor < 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor) {
            long long curr = 0, next = 0;
            for (int i = 0; i < INT_MAX; ++i) {
                curr = divisor << i;
                next = curr << 1;
                if (dividend >= curr && dividend < next) {
                    result += 1 << i;
                    break;
                }
            }
            dividend -= curr;
        }
        return (flag ? -result : result);
    }
};