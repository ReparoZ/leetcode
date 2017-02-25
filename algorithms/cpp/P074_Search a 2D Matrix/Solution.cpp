// Source: https://leetcode.com/problems/search-a-2d-matrix/
// Author: ML3426
// Date: 2017-02-25

/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 先找出在哪一行，再找出那一行是否存在target元素
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = -1, col = int(matrix[0].size() - 1);
        for (int i = 0; i < matrix.size(); ++i) if (matrix[i][col] >= target) { row = i; break; };
        return row == -1 ? false : find(matrix[row].begin(), matrix[row].end(), target) != matrix[row].end();
    }
};