// Source: https://leetcode.com/problems/sort-colors/
// Author: ML3426
// Date: 2017-02-25

/*
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * 
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 * 
 * Could you come up with an one-pass algorithm using only constant space?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用两个指针指示0和2的边界，遇到0向数组的左部移动，遇到2向数组的右部移动
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 3ms
    void sortColors(vector<int> &nums) {
        int pos0 = 0, pos2 = (int) (nums.size() - 1);
        while (nums[pos0] == 0) ++pos0;
        while (nums[pos2] == 2) --pos2;
        int i = pos0;

        while (i <= pos2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[pos0++]);
                if (nums[i] < pos0) i = pos0;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[pos2--]);
            } else i++;
        }
    }
};