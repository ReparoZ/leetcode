// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author: ML3426
// Date: 2017-08-05

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 记录趋势，每次涨到高点就卖，低点就卖即可，其他不买不卖的点可以看做卖出直接买入，增加的收益也为0
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    int maxProfit(vector<int> &prices) {
        int lastLower = INT_MAX, last = INT_MAX, sum = 0;
        for (int price : prices) {
            if (price < last) {
                sum += last - lastLower;
                lastLower = last = price;
            } else if (price > last) {
                last = price;
            }
        }
        return sum + (last - lastLower);
    }
};