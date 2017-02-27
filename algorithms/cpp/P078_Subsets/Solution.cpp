// Source: https://leetcode.com/problems/subsets/
// Author: ML3426
// Date: 2017-02-27

/*
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 树的遍历，利用last保存每一次遍历的结果
    // 时间复杂度为O(2^N)，空间复杂度为O(N)
    // Time: 6ms
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<pair<vector<int>, int>> last = {{{}, -1}};
        res.push_back({});

        for (int i = 0; i < nums.size(); ++i) {
            vector<pair<vector<int>, int>> anotherLast;
            for (int j = 0; j < last.size(); ++j) {
                for (int k = last[j].second + 1; k < nums.size(); ++k) {
                    vector<int> temp = last[j].first;
                    temp.push_back(nums[k]);
                    anotherLast.push_back({temp, k});
                    res.push_back(temp);
                }
            }
            last = anotherLast;
        }

        return res;
    }
};