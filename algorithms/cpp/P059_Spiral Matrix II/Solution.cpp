// Source: https://leetcode.com/problems/spiral-matrix-ii/
// Author: ML3426
// Date: 2017-02-19

/*
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 环形移动坐标，利用left，right，top，down来确定边界
    // 时间复杂度为O(MN)，空间复杂度为O(1)
    // Time: 3ms
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;

        int left = 0, right = n - 1, top = 0, down = n - 1;
        int row = 0, col = 0;
        while (true) {
            if (left > right || top > down) break;
            while (col <= right) res[row][col++] = num++;
            col = right--;
            row++;
            while (row <= down) res[row++][col] = num++;
            row = down--;
            col--;
            if (left > right || top > down) break;
            while (col >= left) res[row][col--] = num++;
            col = left++;
            row--;
            while (row > top) res[row--][col] = num++;
            row = ++top;
            ++col;
        }

        return res;
    }
};