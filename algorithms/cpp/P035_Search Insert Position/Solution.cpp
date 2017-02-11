// Source: https://leetcode.com/problems/search-insert-position/
// Author: ML3426
// Date: 2017-02-11

/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 二分搜索法：
    // 时间复杂度为O(lgn)，空间复杂度为O(1)
    // Time: 6ms
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = (int) (nums.size() - 1);

        while (left < right) {
            auto mid = (left + right) / 2;
            if (nums[mid] == target || (mid > 0 && nums[mid] > target && nums[mid - 1] < target)) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return target > nums[left] ? left + 1 : left;
    }
};