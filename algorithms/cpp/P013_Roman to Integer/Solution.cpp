// Source: https://leetcode.com/problems/roman-to-integer/
// Author: ML3426
// Date: 2017-02-04

/*
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 利用一个map储存罗马数字以及其相对应的整数 
    // 利用罗马数字本身的计算规则来算出整数
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time：112ms
    int romanToInt(string s) {
        unordered_map<char, int> roman2int = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int count = roman2int[s[s.size() - 1]];
        for (int i = 0; i < s.size() - 1; ++i) {
            int current = roman2int[s[i]];
            int prev = roman2int[s[i + 1]];
            if (current >= prev) {
                count += current;
            } else {
                count -= current;
            }
        }
        return count;
    }
};