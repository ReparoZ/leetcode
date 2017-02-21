// Source: https://leetcode.com/problems/unique-paths-ii/
// Author: ML3426
// Date: 2017-02-20

/*
 * Follow up for "Unique Paths":
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * 
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 动态规划法
    // 对于格点(i,j)。由于只能从上格点(i-1,j)或左格点(i,j-1)到达，并且两者路径是不重复的，因此path[i][j] = path[i-1][j]+path[i][j-1]
    // 当格点本身为障碍时，path[i][j]为0
    // 时间复杂度为O(MN)，空间复杂度为O(MN)
    // Time: 0ms
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        unsigned long m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) path[i][j] = 0;
                else {
                    int up = i == 0 ? 0 : path[i - 1][j];
                    int left = j == 0 ? 0 : path[i][j - 1];
                    path[i][j] = i == 0 && j == 0 ? 1 : up + left;
                }
            }
        }
        return obstacleGrid[m - 1][n - 1] != 1 ? path[m - 1][n - 1] : 0;
    }
};