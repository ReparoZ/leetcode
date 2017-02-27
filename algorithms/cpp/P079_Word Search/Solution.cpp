// Source: https://leetcode.com/problems/word-search/
// Author: ML3426
// Date: 2017-02-27

/*
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * 
 * For example,
 * Given board =
 * 
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // DFS
    // 时间复杂度为O(MN^2)，空间复杂度为O(1)
    // Time: 9ms
    bool exist(vector<vector<char>> &board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    bool result = exist(board, word, 0, i, j);
                    if (result) return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string &word, int index, int row, int col) {
        if (index == word.length()) return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] !=
                                                                                   word[index])
            return false;

        char curr = '\0';
        swap(board[row][col], curr);
        bool res = exist(board, word, index + 1, row - 1, col)
                   || exist(board, word, index + 1, row + 1, col)
                   || exist(board, word, index + 1, row, col - 1)
                   || exist(board, word, index + 1, row, col + 1);

        swap(board[row][col], curr);
        return res;
    }
};