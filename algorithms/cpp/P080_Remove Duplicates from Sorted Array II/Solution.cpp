// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author: ML3426
// Date: 2017-02-28

/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 双指针法，另用一个变量记录重复的元素个数，当个数为2时就跳过重复的元素。
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 12ms
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int left = 1, last = nums[0], lastRepeat = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > last || (nums[i] == last && lastRepeat < 2)) {
                swap(nums[left], nums[i]);
                lastRepeat = ((nums[left] == last && lastRepeat == 1) ? 2 : 1);
                last = nums[left];
                ++left;
            }
        }

        return left;
    }
};