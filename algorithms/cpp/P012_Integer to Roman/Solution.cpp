// Source: https://leetcode.com/problems/integer-to-roman/
// Author: ML3426
// Date: 2017-02-04

/*
 * Given an integer, convert it to a roman numeral.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    // 不使用map，根据罗马数字M、D、C、L、X、V、I与数字1000、500、100、50、10、5、1，算出num中有多少个1000、多少个500...多少个1，
    // 然后从大到小将其拼接成字符串，拼接时注意处理900、400、90、40、9、4这些特殊情况。
    // 时间复杂度为O(1)，空间复杂度为O(1)
    // Time: 52ms
    string intToRoman1(int num) {
        string s;
        int m_num = num / 1000;
        num %= 1000;
        int d_num = num / 500;
        num %= 500;
        int c_num = num / 100;
        num %= 100;
        int l_num = num / 50;
        num %= 50;
        int x_num = num / 10;
        num %= 10;
        int v_num = num / 5;
        num %= 5;
        int i_num = num;
        for (int i = 0; i < m_num; ++i) {
            s += 'M';
        }
        if (d_num == 1 && c_num == 4) s += "CM";
        else {
            if (d_num == 1) s += "D";
            if (c_num == 4) s += "CD";
            else {
                for (int i = 0; i < c_num; ++i) {
                    s += "C";
                }
            }
        }
        if (l_num == 1 && x_num == 4) s += "XC";
        else {
            if (l_num == 1) s += "L";
            if (x_num == 4) s += "XL";
            else {
                for (int i = 0; i < x_num; ++i) {
                    s += "X";
                }
            }
        }
        if (v_num == 1 && i_num == 4) s += "IX";
        else {
            if (v_num == 1) s += "V";
            if (i_num == 4) s += "IV";
            else {
                for (int i = 0; i < i_num; ++i) {
                    s += "I";
                }
            }
        }
        return s;
    }

    // 利用map，然后从大数开始，循环在num中减掉，减掉一个数拼接一个数就行。
    // 时间复杂度为O(1)，空间复杂度为O(1)
    // Time: 68ms
    string intToRoman2(int num) {
        map<int, string> int2roman = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"}
        };
        string s;
        for (auto i = int2roman.rbegin(); i != int2roman.rend(); ++i) {
            while (num >= (*i).first) {
                s += (*i).second;
                num -= (*i).first;
            }
        }
        return s;
    }
};