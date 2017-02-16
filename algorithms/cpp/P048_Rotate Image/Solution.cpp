// Source: https://leetcode.com/problems/rotate-image/
// Author: ML3426
// Date: 2017-02-16

/*
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Follow up:
 * Could you do this in-place?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 计算出每个点将会被换到的坐标，从外圈开始向内一圈一圈的交换元素
    // 时间复杂度为O(N^2)，空间复杂度为O(1)
    // Time: 3ms
    void rotate(vector<vector<int>>& matrix) {
        unsigned long n = matrix.size();
        unsigned long round = n / 2;

        for (int i = 0; i < round; ++i) {
            for (int j = 0; j < n - 2 * i - 1; ++j) {
                int temp = matrix[i][i + j];
                swap(temp, matrix[i + j][n - i - 1]);
                swap(temp, matrix[n - i - 1][n - i - j - 1]);
                swap(temp, matrix[n - i - j - 1][i]);
                swap(temp, matrix[i][i + j]);
            }
        }
    }
};