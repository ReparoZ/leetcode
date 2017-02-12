// Source: https://leetcode.com/problems/sudoku-solver/
// Author: ML3426
// Date: 2017-02-12

/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * You may assume that there will be only one unique solution.
 * 
 * http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
 * 
 * A sudoku puzzle...
 * 
 * http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png
 * 
 * ...and its solution numbers marked in red.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> rowRecord[10];
    unordered_set<int> colRecord[10];
    unordered_set<int> sqrRecord[10];

    // 回溯法
    // Time: 42ms
    void solveSudoku(vector<vector<char>> &board) {
        init(board);

        pair<int, int> point = findNext(board, 0, 0);
        solveSudoku(board, point.first, point.second);
    }

    void init(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            auto row = board[i];
            for (int j = 0; j < board[i].size(); ++j) {
                char cell = board[i][j];
                if (cell == '.') {
                    continue;
                } else {
                    int cellNum = cell - '0';
                    int cellSqr = (i / 3) * 3 + (j / 3) + 1;
                    rowRecord[cellNum].insert(i);
                    colRecord[cellNum].insert(j);
                    sqrRecord[cellNum].insert(cellSqr);
                }
            }
        }
    }

    bool isValid(int row, int col, int val) {
        int cellSqr = (row / 3) * 3 + (col / 3) + 1;
        return !(rowRecord[val].find(row) != rowRecord[val].end() ||
                 colRecord[val].find(col) != colRecord[val].end() ||
                 sqrRecord[val].find(cellSqr) != sqrRecord[val].end());
    }

    pair<int, int> findNext(vector<vector<char>> &board, int rowIndex, int colIndex) {
        for (int i = rowIndex; i < board.size(); ++i) {
            int colSize = int(board[i].size());
            for (int j = colIndex; j < colSize; ++j) {
                if (board[i][j] == '.') {
                    return {i, j};
                }
            }
            colIndex = 0;
        }
        return {-1, -1};
    };

    bool solveSudoku(vector<vector<char>> &board, int row, int col) {
        if (row == -1 && col == -1) return true;
        int cellSqr = (row / 3) * 3 + (col / 3) + 1;
        for (int i = 1; i < 10; ++i) {
            if (isValid(row, col, i)) {
                board[row][col] = char('0' + i);
                rowRecord[i].insert(row);
                colRecord[i].insert(col);
                sqrRecord[i].insert(cellSqr);
                pair<int, int> point = findNext(board, row, col);
                if (solveSudoku(board, point.first, point.second)) {
                    return true;
                } else {
                    rowRecord[i].erase(row);
                    colRecord[i].erase(col);
                    sqrRecord[i].erase(cellSqr);
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
};