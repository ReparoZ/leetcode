// Source: https://leetcode.com/problems/valid-palindrome/
// Author: ML3426
// Date: 2017-10-01

/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 双指针对比
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    bool isPalindrome(string s) {
        int left = 0, right = static_cast<int>(s.length() - 1);
        while (left <= right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else if (tolower(s[left]) != tolower(s[right])) return false;
            else ++left, --right;
        }
        return true;
    }
};