// Source: https://leetcode.com/problems/remove-element/
// Author: ML3426
// Date: 2017-02-10

/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * 
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * 
 * Your function should return length = 2, with the first two elements of nums being 2.
 * 
 * Hint:
 * 
 * Try two pointers.
 * Did you use the property of "the order of elements can be changed"?
 * What happens when the elements to remove are rare?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用指针，当遇到指定的数字时将其从数组中删除
    // 返回的数组只包含所需要的非指定的元素
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    int removeElement1(vector<int> &nums, int val) {
        if (nums.size() == 0) return 0;
        auto iter = nums.begin();

        while (iter != nums.end()) {
            if (*iter == val) {
                iter = nums.erase(iter);
            } else {
                iter++;
            }
        }

        return (int) nums.size();
    }

    // 双指针法
    // 将非指定的数字向前移动
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    int removeElement2(vector<int> &nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }

    // 双指针法
    // 将指定的数字向后移动，对于指定数字的存在比较少的时候效率更高
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 3ms
    int removeElement3(vector<int> &nums, int val) {
        unsigned long left = 0;
        unsigned long right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return (int) right;
    }
};