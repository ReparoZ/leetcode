// Source: https://leetcode.com/problems/valid-sudoku/
// Author: ML3426
// Date: 2017-02-12

/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * 
 * http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
 * 
 * A partially filled sudoku which is valid.
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 用三个set数组来保存一个数字所出现的行和列和9宫格
    // 出现重复则说明此数独不合理
    // 时间复杂度为O(N)，空间复杂度为O(N) N为数独的格数
    // Time: 15ms
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_set<int> rowRecord[10];
        unordered_set<int> colRecord[10];
        unordered_set<int> sqrRecord[10];

        for (int i = 0; i < board.size(); ++i) {
            auto row = board[i];
            for (int j = 0; j < board[i].size(); ++j) {
                char cell = board[i][j];
                if (cell == '.') {
                    continue;
                } else {
                    int cellNum = cell - '0';
                    int cellSqr = (i / 3) * 3 + (j / 3) + 1;
                    if (rowRecord[cellNum].find(i) != rowRecord[cellNum].end() ||
                        colRecord[cellNum].find(j) != colRecord[cellNum].end() ||
                        sqrRecord[cellNum].find(cellSqr) != sqrRecord[cellNum].end()) {
                        return false;
                    }
                    rowRecord[cellNum].insert(i);
                    colRecord[cellNum].insert(j);
                    sqrRecord[cellNum].insert(cellSqr);
                }
            }
        }

        return true;
    }
};