// Source: https://leetcode.com/problems/set-matrix-zeroes/
// Author: ML3426
// Date: 2017-02-25

/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * 
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 利用unordered_set保存需要清除的行和列，再进行清除
    // 时间复杂度为O(N^2)，空间复杂度为O(M+N)
    // Time: 62ms
    void setZeroes1(vector<vector<int>> &matrix) {
        unordered_set<int> zeroRows, zeroCols;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        setZeroes1(matrix, zeroRows, zeroCols);
    }

    // 利用第一行保存需要清除的行和列，并用两个变量单独记录第一行和第一列是否需要进行清除
    // 再分行和列进行清除
    // 时间复杂度为O(N^2)，空间复杂度为O(1)
    // Time: 56ms
    void setZeroes2(vector<vector<int>> &matrix) {
        bool firstRowHasZero = false, firstColHasZero = false;
        for (int i = 0; i < matrix[0].size(); ++i)
            if (matrix[0][i] == 0) {
                firstRowHasZero = true;
                break;
            }

        for (int i = 0; i < matrix.size(); ++i)
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix[0].size(); ++i)
            if (matrix[0][i] == 0) for (int j = 0; j < matrix.size(); ++j) matrix[j][i] = 0;

        for (int i = 1; i < matrix.size(); ++i)
            if (matrix[i][0] == 0) for (int j = 0; j < matrix[i].size(); ++j) matrix[i][j] = 0;

        if (firstRowHasZero)
            for (int i = 0; i < matrix[0].size(); ++i) matrix[0][i] = 0;

        if (firstColHasZero)
            for (int i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
    }

    void setZeroes1(vector<vector<int>> &matrix, unordered_set<int> &rows, unordered_set<int> &cols) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) matrix[i][j] = 0;
            }
        }
    }
};