// Source: https://leetcode.com/problems/subsets-ii/
// Author: ML3426
// Date: 2017-06-09

/*
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 
    // Time: 19ms
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lastNum = -1, lastSize = 0;
        vector<vector<int>> res = {{}};

        for (int i = 0; i < nums.size(); ++i) {
            int appendPos = lastNum == nums[i] ? lastSize : 0;
            auto oldSize = res.size();
            for (int j = appendPos; j < oldSize; ++j) {
                vector<int> elem(res[j]);
                elem.push_back(nums[i]);
                res.push_back(elem);
            }
            lastSize = (int) oldSize;
            lastNum = nums[i];
        }
        return res;
    }
};