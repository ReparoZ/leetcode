// Source: https://leetcode.com/problems/palindrome-number/
// Author: ML3426
// Date: 2017-02-02

/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 */
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    // 用连续的取余和整除每次将最左一位和最右一位取出来，再进行比较，直到比较完所有的位数或者出现不一致
    // 时间复杂度为O(N)，空间复杂度为O(N)，N为数字的位数
    // Time: 86ms
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        x = abs(x);
        int t = x;
        int digitNum = 0;
        while (t != 0) t /=10, ++digitNum;

        while (digitNum > 1) {
            int last = x % 10;
            int first = x / (int) (pow(10, digitNum - 1));
            if (last != first) {
                return false;
            }
            x -= (int) pow(10, digitNum - 1) * first;
            x /= 10;
            digitNum -= 2;
        }

        return true;
    }
};