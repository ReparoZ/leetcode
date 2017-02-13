// Source: https://leetcode.com/problems/combination-sum-ii/
// Author: ML3426
// Date: 2017-02-13

/*
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 每次向combination中放入一个数字，再把问题迭代缩小，其中去掉重复的数字
    // 时间复杂度为O(n*2^n)，空间复杂度为O(n)
    // Time: 13ms
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());

        combinationSum(candidates, target, res, combination, -1);
        return res;
    }

    void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combination,
                        int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }

        for (int i = begin + 1; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
            while (i != candidates.size() && candidates[i] == candidates[i + 1]) ++i;
        }
    }
};