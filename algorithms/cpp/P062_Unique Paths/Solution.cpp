// Source: https://leetcode.com/problems/unique-paths/
// Author: ML3426
// Date: 2017-02-20

/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * http://leetcode.com/wp-content/uploads/2014/12/robot_maze.png
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用阶乘的算法直接根据m和n解出结果
    // 由于中间的结果值太大，res即使是longlong类型都无法保存，因此此方法无效
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: N/A
    int uniquePaths1(int m, int n) {
        if (m > n) return uniquePaths1(n, m);

        int sum = m + n - 2;
        int res = 1;
        for (int i = n; i <= sum; ++i) res *= i;
        for (int i = 1; i < m; ++i) res /= i;
        return (int) res;
    }

    // 动态规划法
    // 对于格点(i,j)。由于只能从上格点(i-1,j)或左格点(i,j-1)到达，并且两者路径是不重复的，因此path[i][j] = path[i-1][j]+path[i][j-1]
    // 时间复杂度为O(MN)，空间复杂度为O(MN)
    // Time: 0ms
    int uniquePaths2(int m, int n) {
        vector<vector<int>> path((unsigned long) m, vector<int>((unsigned long) n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        return path[m - 1][n - 1];
    }
};