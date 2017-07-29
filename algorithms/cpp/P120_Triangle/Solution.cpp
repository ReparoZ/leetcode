// Source: https://leetcode.com/problems/triangle/
// Author: ML3426
// Date: 2017-07-29

/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 到从上一层到下一层的任意一个数，只有两种可能，选择小的一个就可以了
    // 时间复杂度为O(N^2)，空间复杂度为O(N)
    // Time: 6ms
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> result = {0};

        for (auto &currRow : triangle) {
            vector<int> currRes;
            for (int j = 0; j < currRow.size(); ++j) {
                if (j == 0) currRes.push_back(currRow[0] + result[0]);
                else if (j == currRow.size() - 1) 
                    currRes.push_back(currRow[currRow.size() - 1] + result[result.size() - 1]);
                else currRes.push_back(currRow[j] + min(result[j - 1], result[j]));
            }
            result = currRes;
        }
        return *min_element(result.begin(), result.end());
    }
};