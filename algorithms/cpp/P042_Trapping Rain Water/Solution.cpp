// Source: https://leetcode.com/problems/combination-sum-ii/
// Author: ML3426
// Date: 2017-02-13

/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 解释见：https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space/2
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 12ms
    int trap(vector<int> &height) {
        int left = 0;
        int right = (int) (height.size() - 1);
        int res = 0;
        int maxLeft = 0, maxRight = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) maxLeft = height[left];
                else res += maxLeft - height[left];
                left++;
            } else {
                if (height[right] >= maxRight) maxRight = height[right];
                else res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};