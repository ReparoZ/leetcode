// Source: https://leetcode.com/problems/3sum/
// Author: ML3426
// Date: 2017-02-07

/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 双指针法，并在遍历的过程中，跳过那些重复的元素
    // 时间复杂度为O(N^2)，空间复杂度为O(1)
    // Time: 109ms
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {

            int target = -nums[i];
            int front = i + 1;
            unsigned long back = nums.size() - 1;

            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
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