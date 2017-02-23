// Source: https://leetcode.com/problems/climbing-stairs/
// Author: ML3426
// Date: 2017-02-23

/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 */

class Solution {
public:
    // 动态规划法
    // 由于要跳到第i个阶梯，只能由第i-1个阶梯跳1阶或者i-2个阶梯跳两阶实现，因此a[i] = a[i - 1] + a[i - 2]（斐波那契数列）
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 0ms
    int climbStairs(int n) {
        if (n < 2) return 1;
        else {
            int jump2 = 1, jump1 = 1;
            for (int i = 0; i < n - 2; ++i) {
                int now = jump1 + jump2;
                jump2 = jump1;
                jump1 = now;
            }
            return jump1;
        }
    }
};