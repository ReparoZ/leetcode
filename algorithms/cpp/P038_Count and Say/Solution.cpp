// Source: https://leetcode.com/problems/count-and-say/
// Author: ML3426
// Date: 2017-02-13

/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // 按照定义循环生成字符串即可
    // 时间复杂度O(2^k)，空间复杂度为O(2^k)
    // Time: 3ms
    string countAndSay(int n) {
        string res = "1";

        if (n == 1) return res;

        char num;
        int times = 0;
        for (int i = 1; i < n; ++i) {
            num = res[0];
            times = 1;
            string temp = "";
            for (int j = 1; j < res.size(); ++j) {
                if (num == res[j]) {
                    ++times;
                } else {
                    temp += char(times + '0');
                    temp += num;
                    num = res[j];
                    times = 1;
                }
            }
            res = temp;
        }
        return res;
    }
};