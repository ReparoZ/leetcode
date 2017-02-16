// Source: https://leetcode.com/problems/permutations/
// Author: ML3426
// Date: 2017-02-16

/*
 * Given a collection of distinct numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 迭代法
    // 先固定一个数，再求剩下数字的全排列，再将这个数与生成的全排列结合起来
    // 时间复杂度为O(N!)，空间复杂度为O(1)
    // Time: 13ms
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() < 2) return {nums};

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            nums.erase(nums.begin() + i);

            vector<vector<int>> tempRes = permute(nums);
            for (int j = 0; j < tempRes.size(); ++j) {
                tempRes[j].insert(tempRes[j].begin(), curr);
                res.push_back(tempRes[j]);
            }
            
            nums.insert(nums.begin() + i, curr);
        }

        return res;
    }
};