// Source: https://leetcode.com/problems/3sum-closest/
// Author: ML3426
// Date: 2017-02-07

/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 双指针法，并在遍历的过程中，跳过那些重复的元素
    // 时间复杂度为O(N^2)，空间复杂度为O(1)
    // Time: 6ms
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, diff = INT_MAX;
        for (unsigned long i = 0; i < nums.size(); i++) {

            unsigned long front = i + 1, back = nums.size() - 1;
            while (front < back) {
                int sum = nums[i] + nums[front] + nums[back];

                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    res = sum;
                }

                if (sum < target) {
                    front++;
                } else if (sum > target) {
                    back--;
                } else {
                    return sum;
                }
            }
        }
        return res;
    }
};