// Source: https://leetcode.com/problems/next-permutation/
// Author: ML3426
// Date: 2017-02-11

/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 递归解法，从头开始，向下找出下一个排列，如果找不到，就将自己与自己后面的某个大于自身的最小数交换，再使后面升序排列
    // 例如1 3 4 2，由于4 2已经没有更大的排列了，则将3与4交换生成1 4 3 2，再将3 2变为升序排列1 4 2 3
    // 如果从第一个元素开始就已经找不到排列了，则说明已经是最大排列，则将整个vector升序排列
    // 时间复杂度O(N)，空间复杂度为O(1)
    // Time: 19ms
    void nextPermutation1(vector<int> &nums) {
        if (nums.size() < 2) return;

        if (nextPermutation(nums, 0)) return;
        else sort(nums.begin(), nums.end());
    }

    bool nextPermutation(vector<int> &nums, unsigned long start) {
        if (start == nums.size() - 1) return false;
        if (nextPermutation(nums, start + 1)) return true;

        unsigned long min = ULONG_MAX, pos = start;
        for (unsigned long i = start + 1; i < nums.size(); ++i) {
            if (nums[i] > nums[start] && nums[i] < min) {
                min = (unsigned long) nums[i];
                pos = i;
            }
        }
        if (min == nums[start] || min == ULONG_MAX) return false;
        swap(nums[start], nums[pos]);
        sort(nums.begin() + start + 1, nums.end());
        return true;
    }

    // 单趟遍历的解法
    // 过程图在：https://leetcode.com/media/original_images/31_Next_Permutation.gif
    // 时间复杂度O(N)，空间复杂度为O(1)
    // Time: 12ms
    void nextPermutation2(vector<int> &nums) {
        if (nums.size() < 2) return;

        long i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }

        if (i >= 0) {
            long j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};