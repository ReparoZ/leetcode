// Source: https://leetcode.com/problems/powx-n/
// Author: ML3426
// Date: 2017-02-17

/*
 * Implement pow(x, n).
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 利用x平方时，n要除2的规律，减少循环次数
    // 例如5的7次方，将其转化为(5) * 5 ^ 6 -> (5) * 25 ^ 3 -> (5 * 25) * 25 ^ 2 -> 5 * 25 * 625
    // 时间复杂度为O(lgN)，空间复杂度为O(1)
    // Time: 9ms
    double myPow(double x, int n) {
        bool isNeg = n < 0;
        if (n == 0) return 1;
        if (n == INT_MIN) x *= x, n /= 2;
        n = abs(n);

        double mul = 1;
        while (n > 1) {
            if ((n & 1) != 0) {
                mul *= x;
            }
            x *= x;
            n /= 2;
        }

        return isNeg ? 1 / (mul * x) : mul * x;
    }
};