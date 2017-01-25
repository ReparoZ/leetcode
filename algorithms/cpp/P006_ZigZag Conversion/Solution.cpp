// Source: https://leetcode.com/problems/zigzag-conversion/
// Author: ML3426
// Date: 2017-01-25

/* 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 对于排列后的字符按行来进行处理，先拼接第一行，再拼接第二行如此循环
    // 时间复杂度：O(n)，空间复杂度：O(1)
    // Time: 29ms
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        unsigned long len = s.length();
        int group = numRows * 2 - 2;
        string converted = "";
        
        for (int i = 0; i < s.length(); i += group) {
            converted += s[i];
        }
        
        for (int i = 1; i < numRows - 1; ++i) {
            for (int j = i; j < s.length(); j += group) {
                converted += s[j];
                if (j - i + group - i < s.length()) {
                    converted += s[j - i + group - i];
                }
            }
        }
        
        for (int i = numRows - 1; i < s.length(); i += group) {
            converted += s[i];
        }

        return converted;
    }
};