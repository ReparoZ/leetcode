// Source: https://leetcode.com/problems/jump-game-ii/
// Author: ML3426
// Date: 2017-02-15

/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 解释见https://discuss.leetcode.com/topic/3191/o-n-bfs-solution
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 12ms
    int jump(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        int level = 0, currentMax = 0, i = 0, nextMax = 0;
        
        while (currentMax - i + 1 > 0) {
            level++;
            for (; i <= currentMax; ++i) {
                nextMax = max(nextMax, nums[i] + i);
                if (nextMax >= nums.size() - 1) return level;
            }
            currentMax = nextMax;
        }
        return 0;
    }
};