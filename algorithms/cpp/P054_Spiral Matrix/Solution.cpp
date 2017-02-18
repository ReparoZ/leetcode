// Source: https://leetcode.com/problems/spiral-matrix/
// Author: ML3426
// Date: 2017-02-18

/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * 
 * For example,
 * Given the following matrix:
 * 
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 环形移动坐标，利用left，right，top，down来确定边界
    // 时间复杂度为O(MN)，空间复杂度为O(1)
    // Time: 3ms
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;

        int left = 0, right = (int) (matrix[0].size() - 1), top = 0, down = (int) (matrix.size() - 1);
        int row = 0, col = 0;
        while (true) {
            if (left > right || top > down) break;
            while (col <= right) res.push_back(matrix[row][col++]);
            col = right--; row++;
            while (row <= down) res.push_back(matrix[row++][col]);
            row = down--; col--;
            if (left > right || top > down) break;
            while (col >= left) res.push_back(matrix[row][col--]);
            col = left++; row--;
            while (row > top) res.push_back(matrix[row--][col]);
            row = ++top; ++col;
        }

        return res;
    }
};