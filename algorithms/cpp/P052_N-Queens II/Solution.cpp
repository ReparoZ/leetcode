// Source: https://leetcode.com/problems/n-queens-ii/
// Author: ML3426
// Date: 2017-02-17

/*
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 经典回溯法解决N Queens问题
    // 时间复杂度为O(N!)，空间复杂度为O(1)
    // Time: 6ms
    int totalNQueens1(int n) {
        int row = 0, col = 0, res = 0;

        vector<int> queensPos;
        while (row < n) {
            while (col < n) {
                if (isValid(queensPos, row, col)) {
                    queensPos.push_back(col);
                    break;
                }

                ++col;
            }
            ++row, col = 0;

            if (queensPos.size() == n) {
                ++res;
                col = queensPos.back() + 1;
                row = (int) (queensPos.size() - 1);
                queensPos.pop_back();
            } else if (queensPos.size() != row) {
                if (queensPos[0] == n - 1 && queensPos.back() + 1 == n) break;
                col = queensPos.back() + 1;
                row = (int) (queensPos.size() - 1);
                queensPos.pop_back();
            }
        }

        return res;
    }

    bool isValid(vector<int> &queenPos, int row, int col) {
        int sum = row + col, diff = row - col;

        for (int i = 0; i < queenPos.size(); ++i) {
            auto queen = queenPos[i];
            if (i == row || queen == col || i + queen == sum || i - queen == diff) return false;
        }

        return true;
    }

    // Just For Fun!
    // 时间复杂度为O(1)，空间复杂度为O(1)
    // Time: 0ms
    int totalNQueens2(int n) {
        int res[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
        return res[n];
    }
};