// Source: https://leetcode.com/problems/maximal-rectangle/
// Author: ML3426
// Date: 2017-03-02

/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 6.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 将matrix的每一行，转化为从该行起到第一行的每一个矩形的高度（类似于P84的题目），再利用P84的解法解
    // 时间复杂度为O(MN)，空间复杂度为O(1)
    // Time: 9ms
    int maximalRectangle(vector<vector<char>> &matrix) {
        int maxSize = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            if (i != 0) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    matrix[i][j] = (char) (matrix[i][j] == '0' ? '0' : matrix[i - 1][j] + 1);
                }
            }

            maxSize = max(maxSize, largestRectangleArea(matrix[i]));
        }

        return maxSize;
    }

    int largestRectangleArea(vector<char> &heights) {
        if (heights.size() == 0) return 0;
        stack<int> st;
        int MAX = 0;
        heights.push_back('0');
        int leftArea = 0, rightArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int tmp = st.top();
                st.pop();
                leftArea = (st.empty() ? tmp + 1 : tmp - st.top()) * (heights[tmp] - '0');
                rightArea = (i - tmp - 1) * (heights[tmp] - '0');
                if ((leftArea + rightArea) > MAX) MAX = (leftArea + rightArea);
            }
            st.push(i);
        }
        return MAX;
    }
};