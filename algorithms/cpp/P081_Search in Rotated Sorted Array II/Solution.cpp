// Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: ML3426
// Date: 2017-02-28

/*
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Write a function to determine if a given target is in the array.
 * 
 * The array may contain duplicates.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 二分搜索法
    // 时间复杂度为O(LGN)，最差的时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    bool search(vector<int> &nums, int target) {
        if (nums.empty()) return false;
        int lo = 0, hi = (int) (nums.size() - 1);
        int mid = 0;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[hi]) {
                if (nums[mid] > target && nums[lo] <= target) hi = mid;
                else lo = mid + 1;
            } else if (nums[mid] < nums[hi]) {
                if (nums[mid] < target && nums[hi] >= target) lo = mid + 1;
                else hi = mid;
            } else {
                hi--;
            }

        }
        return nums[lo] == target;
    }
};

};