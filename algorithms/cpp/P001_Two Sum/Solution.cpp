// Source: https://leetcode.com/problems/two-sum/
// Author: ML3426
// Date: 2017-01-14

/* 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 *         Given nums = [2, 7, 11, 15], target = 9,
 *
 *         Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * UPDATE (2016/2/13):
 * The return format had been changed to zero-based indices. Please read the above updated description carefully.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 两重循环相加解题，时间复杂度为O(n^2)，空间复杂度1
    // Time: 839 ms
    vector<int> twoSum1(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }

    // 遍历每一个数，然后找出是否有对应的数，时间复杂度大约O(nlgn~n^2)，空间复杂度1
    // Time: 572 ms
    vector<int> twoSum2(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            auto item = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (item != nums.end() && item != nums.begin() + i) {
                return {i, (int) (item - nums.begin())};
            }
        }
        return {0, 0};
    }

    // 使用一个额外的map来存取数字及其在数组中的位置，利用map优秀的查找性能来获取数字的位置O(n)，两次遍历，先插入数据再查找。
    // 时间复杂度为O(n)，空间复杂度为O(n)
    // Time: 16 ms
    vector<int> twoSum3(vector<int> &nums, int target) {
        unordered_map<int, int> cache_map;

        for (int i = 0; i < nums.size(); ++i) {
            cache_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (cache_map.find(target - nums[i]) != cache_map.end() && i != cache_map[target - nums[i]]) {
                return {i, cache_map[target - nums[i]]};
            }
        }
        return {0, 0};
    }

    // 使用一个额外的map来存取数字及其在数组中的位置，利用map优秀的查找性能来获取数字的位置O(n)，一次遍历。
    // 时间复杂度为O(n)，空间复杂度为O(n)
    // Time: 16ms
    vector<int> twoSum4(vector<int> &nums, int target) {
        unordered_map<int, int> cache_map;

        for (int i = 0; i < nums.size(); ++i) {
            if (cache_map.find(target - nums[i]) != cache_map.end() && i != cache_map[target - nums[i]]) {
                return {cache_map[target - nums[i]], i};
            } else {
                cache_map[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};
