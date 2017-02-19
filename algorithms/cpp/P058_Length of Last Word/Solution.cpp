// Source: https://leetcode.com/problems/length-of-last-word/
// Author: ML3426
// Date: 2017-02-19

/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 3ms
    int lengthOfLastWord(string s) {
        long pos = s.length() - 1, res = 0;
        while (pos > 0 && s[pos] == ' ') --pos;
        while (pos >= 0 && s[pos] != ' ') ++res, --pos;
        return int(res);
    }
};