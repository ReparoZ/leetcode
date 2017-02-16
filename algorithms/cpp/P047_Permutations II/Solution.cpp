// Source: https://leetcode.com/problems/permutations-ii/
// Author: ML3426
// Date: 2017-02-16

/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 迭代法
    // 先固定一个数，再求剩下数字的全排列，再将这个数与生成的全排列结合起来
    // 在循环求全排列的时候，如果发现这一个数与上一个数一致，则continue掉避免重复
    // 时间复杂度为O(N!)，空间复杂度为O(1)
    // Time: 32ms
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.size() < 2) return {nums};

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int curr = nums[i];
            nums.erase(nums.begin() + i);

            vector<vector<int>> tempRes = permuteUnique(nums);
            for (int j = 0; j < tempRes.size(); ++j) {
                tempRes[j].insert(tempRes[j].begin(), curr);
                res.push_back(tempRes[j]);
            }

            nums.insert(nums.begin() + i, curr);
        }

        return res;
    }
};