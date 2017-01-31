// Source: https://leetcode.com/problems/reverse-integer/
// Author: ML3426
// Date: 2017-01-31

/* 
 * Reverse digits of an integer.
 * 
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * 
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 * 
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * 
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 * 
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * 
 * Update (2014-11-10):
 * Test cases had been added to test the overflow behavior.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 此题对于并不是难在如何翻转一个数，而是如何判断边界情况
    // 使用一个更大的类型来存储翻转的结果，最后如果翻转的结果大于原类型的边界则单独处理
    // 此方法成立的前提是一定是要有一个比原类型大的类型
    // 时间复杂度：O(N)，空间复杂度O(N)。N为x的位数。
    // Time: 9ms
    int reverse1(int x) {
        long reversed = 0;

        while (x) {
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }

        return (reversed > INT_MAX || reversed < INT_MIN) ? 0 : (int) reversed;
    }

    // 在每一次翻转之前判断结果将会不会超出原类型的边界。经分析可知，只要之前判断了，则reversed = reversed * 10 + x % 10;
    // 这一步是不会超出边界的。
    // 时间复杂度：O(N)，空间复杂度O(N)。N为x的位数。
    // Time: 9ms
    int reverse2(int x) {
        int reversed = 0;
        while (x) {
            if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
                return 0;
            }
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return reversed;
    }
};