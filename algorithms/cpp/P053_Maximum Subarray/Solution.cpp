// Source: https://leetcode.com/problems/maximum-subarray/?tab=Description
// Author: ML3426
// Date: 2017-02-18

/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * 
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * 
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 遍历数组，最大的和的数组，其相邻的左侧子数组必然小于0，因此可以遍历数组，每当和小于0时重置sum，并且记录最大的和maxSum。
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    int maxSubArray1(vector<int> &nums) {
        int sum = 0, maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > maxSum) maxSum = sum;

            if (sum < 0) sum = 0;
        }

        return maxSum;
    }

    // 分治法
    // mx (largest sum of this subarray), 
    // lmx(largest sum starting from the left most element),
    // rmx(largest sum ending with the right most element),
    // sum(the sum of the total subarray).
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 9ms
    int maxSubArray2(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int mx, lmx, rmx, sum;
        maxSubArray2(nums, 0, (int) (nums.size() - 1), mx, lmx, rmx, sum);
        return mx;
    }

    void maxSubArray2(vector<int> &nums, int l, int r, int &mx, int &lmx, int &rmx, int &sum) {
        if (l == r) {
            mx = lmx = rmx = sum = nums[l];
        } else {
            int m = (l + r) / 2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            maxSubArray2(nums, l, m, mx1, lmx1, rmx1, sum1);
            maxSubArray2(nums, m + 1, r, mx2, lmx2, rmx2, sum2);
            mx = max(max(mx1, mx2), rmx1 + lmx2);
            lmx = max(lmx1, sum1 + lmx2);
            rmx = max(rmx2, sum2 + rmx1);
            sum = sum1 + sum2;
        }
    }
};