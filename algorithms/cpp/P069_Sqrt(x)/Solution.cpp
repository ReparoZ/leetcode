// Source: https://leetcode.com/problems/sqrtx/
// Author: ML3426
// Date: 2017-02-23

/*
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 */

class Solution {
public:
    // 用二分法逼近所求的数的根
    // 时间复杂度为O(lgN)，空间复杂度为O(1)
    // Time: 6ms
    int mySqrt1(int x) {
        int limit = 46340;  // root of Integer.MAX_VALUE
        int start = 0, end = x / 2 + 1, mid;
        while (true) {
            mid = (start + end) / 2;
            if (mid > limit) {
                end = mid - 1;
                continue;
            }
            int curr = mid * mid, next = (mid + 1) * (mid + 1);
            if (curr <= x && (next > x || next < 0)) {
                return mid;
            } else {
                if (mid * mid < x) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
    }
    
    // 利用牛顿法逼近方程的根
    // Time: 6ms
    int mySqrt2(int x) {
        if (x == 0) return 0;
        double last = 0, res = 1;
        while (int(res) != int(last)) {
            last = res;
            res = (last + x / res) / 2;
        }
        return int(res);
    }
};