// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: ML3426
// Date: 2017-08-04

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * 
 * Example 1:
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 * 
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 * Example 2:
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 * 
 * In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用两个变量记录左右的小值和大值，遍历进行左右的替换
    // 时间复杂度为O(N)，空间复杂度为O(1) 
    // Time: 6ms
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        
        int maxDiff = 0;
        int left = prices[0], right = prices[0];
        for (int price : prices) {
            if (price < left) {
                maxDiff = max(maxDiff, right - left);
                left = right = price;
            } else if (price > right) {
                right = price;
            }
        }
        return max(maxDiff, right - left);
    }
};