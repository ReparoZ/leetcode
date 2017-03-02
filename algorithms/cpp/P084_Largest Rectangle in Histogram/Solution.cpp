// Source: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: ML3426
// Date: 2017-02-28

/*
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/04/histogram.png
 * 
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/04/histogram_area.png
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 解释见：http://www.cnblogs.com/felixfang/p/3676193.html
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 16ms
    int largestRectangleArea(vector<int> &heights) {
        if (heights.size() == 0) return 0;
        stack<int> st;
        int MAX = 0;
        heights.push_back(0);
        int leftArea = 0, rightArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int tmp = st.top();
                st.pop();
                leftArea = (st.empty() ? tmp + 1 : tmp - st.top()) * heights[tmp];
                rightArea = (i - tmp - 1) * heights[tmp];
                if ((leftArea + rightArea) > MAX) MAX = (leftArea + rightArea);
            }
            st.push(i);
        }
        return MAX;
    }
};