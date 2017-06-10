// Source: https://leetcode.com/problems/decode-ways/
// Author: ML3426
// Date: 2017-06-10

/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 * 
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * The number of ways decoding "12" is 2.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // preDuNum指的是一个数字分割组中最前面大于等于"10"的个数，例如10|2|21则属于preDu
    // 如果遇到只能为单个数字的数，例如7 8 9，则重置preDunum为0
    // 如果遇到前面是可以与后面的数组成preDu的，则将res*2-preDu再算出新的preDuNum
    // 注意类似于0，00，01，10，17，1717171717之类的测试集
    // Time: 3ms
    int numDecodings(string s) {
        int res = 0, preDuNum = 0;
        for (int i = (int) (s.length() - 1); i >= 0; --i) {
            if (s[i] == '0') {
                if ((i == 0 || s[--i] > '2' || s[i] < '1')) return 0;
                else {res = res == 0 ? 1 : res; preDuNum = 1;}
            } else if (i == s.length() - 1) {
                ++res;
            } else if (s[i] < '2' || s[i] == '2' && s[i + 1] < '7') {
                int newDuNum = res - preDuNum;
                res = res * 2 - preDuNum;
                preDuNum = newDuNum;
            } else preDuNum = 0;
        }
        return res;
    }
};