// Source: https://leetcode.com/problems/jump-game/
// Author: ML3426
// Date: 2017-02-18

/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 * 
 * A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int maxReach = 0;
        
        for (int i = 0; i < nums.size() && i <= maxReach; ++i) {
            maxReach = max(maxReach, nums[i] + i);
            if (maxReach >= nums.size() - 1) return true;
        }

        return false;
    }
};