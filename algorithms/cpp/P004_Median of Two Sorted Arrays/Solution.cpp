// Source: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author: ML3426
// Date: 2017-01-20

/* 
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 最原始的方法，由于两个数组都是已经被排过序的数组，因此直接从开始出找到位于中间的两个数字即可。
    // 时间复杂度：O(n)，空间复杂度：O(1)
    // Time: 28ms(beats 99.49%..)
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2) {
        auto elem_n = nums1.size() + nums2.size();
        auto round = elem_n % 2 == 1 ? elem_n / 2 : elem_n / 2 - 1;

        int ptr_1 = 0, ptr_2 = 0, cnt = 0;
        for (cnt; cnt < round; ++cnt) {
            if (getNum(nums1, ptr_1) < getNum(nums2, ptr_2)) {
                ptr_1++;
            } else {
                ptr_2++;
            }
        }
        
        int median_1 = getNum(nums1, ptr_1) < getNum(nums2, ptr_2) ? getNum(nums1, ptr_1++) : getNum(nums2, ptr_2++);
        int median_2 = getNum(nums1, ptr_1) < getNum(nums2, ptr_2) ? getNum(nums1, ptr_1) : getNum(nums2, ptr_2);

        return elem_n % 2 == 1 ? median_1 : (median_1 + median_2) / 2.0;
    }
    
    int getNum(vector<int> &nums, int pos) {
        return pos < nums.size() ? nums[pos] : INT_MAX;
    }

    // 分治法，将问题抽象为找出一定范围之内的第K个元素这样的问题
    // 时间复杂度：O(log(n+m))，空间复杂度：O(1)
    // Time: 36ms
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
        auto elem_n = nums1.size() + nums2.size();
        auto middle = elem_n / 2;
        
        if (elem_n % 2 == 0) {
            return (findKthElem(nums1, nums2, 0, 0, (int) middle) + findKthElem(nums1, nums2, 0, 0, (int) middle + 1)) / 2;
        } else {
            return findKthElem(nums1, nums2, 0, 0, (int) middle + 1);
        }
    }
    
    double findKthElem(vector<int> &nums1, vector<int> &nums2, int start1, int start2, int k) {
        auto length1 = nums1.size() - start1, length2 = nums2.size() - start2;
        if (length1 > length2) {
            return findKthElem(nums2, nums1, start2, start1, k);
        }
        
        if (length1 == 0) {
            return nums2[start2 + k - 1];
        }
        
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        
        int pos1 = min(k / 2, (const int &) length1);
        int pos2 = k - pos1;
        
        if (nums1[start1 + pos1 - 1] < nums2[start2 + pos2 - 1]) {
            return findKthElem(nums1, nums2, start1 + pos1, start2, k - pos1);
        } else if (nums1[start1 + pos1 - 1] > nums2[start2 + pos2 - 1]) {
            return findKthElem(nums1, nums2, start1, start2 + pos2, k - pos2);
        } else {
            return nums1[start1 + pos1 - 1];
        }
    }
};