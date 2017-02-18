// Source: https://leetcode.com/problems/n-queens/
// Author: ML3426
// Date: 2017-02-18

/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 经典回溯法解决N Queens问题
    // 时间复杂度为O(N!)，空间复杂度为O(1)
    // Time: 6ms
    vector<vector<string>> solveNQueens(int n) {
        int row = 0, col = 0;
        vector<vector<string>> res;

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
                res.push_back(makeBoard(queensPos, n));
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

    vector<string> makeBoard(vector<int> &queensPos, int n) {
        vector<string> res;

        for (int i = 0; i < queensPos.size(); ++i) {
            string line((unsigned long) n, '.');
            line[queensPos[i]] = 'Q';
            res.push_back(line);
        }

        return res;
    }
};
