// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: ML3426
// Date: 2017-02-10

/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * For example,
 * Given input array nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 记录之前遍历的数字，当遇到重复的数字时将其从数组中删除
    // 返回的数组只包含所需要的非重复元素
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 52ms
    int removeDuplicates1(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int last = nums[0];
        auto iter = nums.begin();
        iter++;

        while (iter != nums.end()) {
            if (*iter == last) {
                iter = nums.erase(iter);
            } else {
                last = *iter;
                iter++;
            }
        }

        return (int) nums.size();
    }

    // 双指针法，将非重复数字前移
    // 返回的数组大小大于非重复数字个数
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 26ms
    int removeDuplicates2(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};