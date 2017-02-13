// Source: https://leetcode.com/problems/combination-sum/
// Author: ML3426
// Date: 2017-02-13

/*
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * [
 *   [7],
 *   [2, 2, 3]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 每次向combination中放入一个数字，再把问题迭代缩小
    // 时间复杂度为O(n*2^n)，空间复杂度为O(n)
    // Time: 13ms
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
	sort(candidates.begin(), candidates.end());

        combinationSum(candidates, target, res, combination, 0);
        return res;
    }

    void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combination,
                        int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }

        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
