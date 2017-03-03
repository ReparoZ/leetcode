// Source: https://leetcode.com/problems/merge-sorted-array/
// Author: ML3426
// Date: 2017-03-03

/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 维护三个指针用来指示两个数组以及最终的结果数组的位置
    // 时间复杂度为O(M+N)，空间复杂度为O(1)
    // Time: 6ms
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        long index = m + n - 1, index1 = m - 1, index2 = n - 1;

        while (index >= 0) {
            int temp;
            if (index1 >= 0 && index2 >= 0) {
                temp = nums1[index1] > nums2[index2] ? nums1[index1--] : nums2[index2--];
            } else if (index1 >= 0) {
                temp = nums1[index1--];
            } else {
                temp = nums2[index2--];
            }

            nums1[index--] = temp;
        }
    }
};