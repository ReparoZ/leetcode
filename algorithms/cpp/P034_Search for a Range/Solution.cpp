// Source: https://leetcode.com/problems/search-for-a-range/
// Author: ML3426
// Date: 2017-02-11

/*
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用二分搜索法，先找左边界，再找右边界
    // 时间复杂度为O(lgn)，空间复杂度为O(1)
    // Time: 9ms
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int i = 0, j = (int) (nums.size() - 1);
        vector<int> ret(2, -1);

        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] < target) i = mid + 1;
            else j = mid;
        }
        if (nums[i] != target) return ret;
        else ret[0] = i;

        j = (int) (nums.size() - 1);
        while (i < j) {
            int mid = (i + j) / 2 + 1;
            if (nums[mid] > target) j = mid - 1;
            else i = mid;
        }
        ret[1] = j;
        return ret;
    }
};