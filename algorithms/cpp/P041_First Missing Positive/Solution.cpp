// Source: https://leetcode.com/problems/combination-sum-ii/
// Author: ML3426
// Date: 2017-02-13

/*
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 将数组中的每个正数，放到他的本身的序号所在的位置，例如数字1应该放在nums[0]，数字5放在nums[4]的位置，
    // 然后找到第一个位置不是他本身的数，则那个位置本应在的正数就是缺失的正数。
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        return (int) nums.size() + 1;
    }
};