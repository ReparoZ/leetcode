// Source: https://leetcode.com/problems/unique-paths-ii/
// Author: ML3426
// Date: 2017-02-20

/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 动态规划法
    // 对于格点(i,j)。由于只能从上格点(i-1,j)或左格点(i,j-1)到达，并且两者路径是不重复的，因此path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j]
    // 时间复杂度为O(MN)，空间复杂度为O(MN)
    // Time: 9ms
    int minPathSum(vector<vector<int>> &grid) {
        unsigned long m = grid.size(), n = grid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = i == 0 ? INT_MAX : path[i - 1][j];
                int left = j == 0 ? INT_MAX : path[i][j - 1];
                path[i][j] = (i == 0 && j == 0 ? 0 : min(up, left)) + grid[i][j];
            }
        }
        return path[m - 1][n - 1];
    }
};