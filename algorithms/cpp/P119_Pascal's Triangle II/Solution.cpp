// Source: https://leetcode.com/problems/pascals-triangle-ii/
// Author: ML3426
// Date: 2017-07-29

/**
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 按层计算
    // 时间复杂度为O(N^2)，空间复杂度为O(N)
    // Time: 0ms
    vector<int> getRow(int rowIndex) {
        vector<int> lastLayer;
        for (int i = 0; i <= rowIndex; ++i) {
            vector<int> curLayer = {1};
            for (int j = 0; j <= i - 2; ++j) {
                curLayer.push_back(lastLayer[j] + lastLayer[j + 1]);
            }
            if (i > 0) curLayer.push_back(1);
            lastLayer = curLayer;
        }
        return lastLayer;
    }
};
