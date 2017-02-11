// Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: ML3426
// Date: 2017-02-11

/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // 最简单的暴力解法
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    int search1(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (target == nums[i]) {
                return i;
            }
        }
        return -1;
    }

    // 二分查找法
    // Explanation
    // Let's say nums looks like this: [12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    // Because it's not fully sorted, we can't do normal binary search. But here comes the trick:
    // 
    // If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
    // [12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]
    // If target is let's say 7, then we adjust nums to this:
    // [-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    // And then we can simply do ordinary binary search.
    // 时间复杂度为O(lgN)，空间复杂度为O(1)
    // Time: 3ms
    int search2(vector<int> &nums, int target) {
        int low = 0, high = (int) nums.size();
        while (low < high) {
            int mid = (low + high) / 2;

            double num = (nums[mid] < nums[0]) == (target < nums[0]) ? nums[mid]
                                                                     : target < nums[0] ? -INFINITY : INFINITY;
            if (num < target)
                low = mid + 1;
            else if (num > target)
                high = mid;
            else
                return mid;
        }
        return -1;
    }
};