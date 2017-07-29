// Source: https://leetcode.com/problems/pascals-triangle/
// Author: ML3426
// Date: 2017-07-28

/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 按层计算
    // 时间复杂度为O(N^2)，空间复杂度为O(N^2)
    // Time: 3ms
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> lastLayer; 
        for (int i = 0; i < numRows; ++i) {
            vector<int> curLayer = {1};
            for (int j = 0; j <= i - 2; ++j) {
                curLayer.push_back(lastLayer[j] + lastLayer[j + 1]);
            }
            if (i > 0) curLayer.push_back(1);
            result.push_back(lastLayer = curLayer);
        }
        return result;
    }
};
