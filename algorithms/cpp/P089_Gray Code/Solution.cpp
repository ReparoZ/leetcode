// Source: https://leetcode.com/problems/gray-code/
// Author: ML3426
// Date: 2017-06-09

/*
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * 
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 * 
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // 此格雷码解法使用了迭代法，由于规模为N的格雷码由两部分组成，前一部分与规模为N-1的格雷码相同
    // 后一部分则与规模为N-1的格雷码刚好相反，并在前面加上一个二进制1
    // 例如规模为N的格雷码与规模为1的格雷码相同，为{0, 1}
    // 后半部分就是将{0, 1}反过来变成{1, 0}再加上一个1变为{11, 10}
    // 时间复杂度为O(2^N)，空间复杂度为O(2^N)
    // Time: 6ms
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        else if (n == 1) return {0, 1};
        else {
            vector<int> res = grayCode(n - 1);
            for (int i = res.size() - 1; i >= 0; --i) {
                res.push_back(res[i] + pow(2, n - 1));
            }
            return res;
        }
    }
};