// Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: ML3426
// Date: 2017-02-07

/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 仿照P015的方法，先固定一个数，将问题转化为3Sum，再使用P015的方法，算出threeSum的结果即可
    // 时间复杂度为O(N^3)，空间复杂度为O(1)
    // Time: 29ms
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;

        if (nums.size() < 4) {
            return res;
        }

        sort(nums.begin(), nums.end());
        for (unsigned long i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            vector<int> rest(nums.begin() + i + 1, nums.end());
            vector<vector<int>> ret = threeSum(rest, target - nums[i]);
            for (int j = 0; j < ret.size(); ++j) {
                ret[j].insert(ret[j].begin(), nums[i]);
                res.push_back(ret[j]);
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {

            int innerTarget = target - nums[i];
            int front = i + 1;
            unsigned long back = nums.size() - 1;

            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < innerTarget)
                    front++;
                else if (sum > innerTarget)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    while (front < back && nums[front] == triplet[1]) front++;
                    while (front < back && nums[back] == triplet[2]) back--;
                }

            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;

        }

        return res;
    }
};