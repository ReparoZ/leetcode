// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author: ML3426
// Date: 2017-08-12

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 分别得出以i点为分割点，左半段最大收益的数组left，和右半段最大收益的数组right
    // leftProfit[i] = max(prices[i] - leftMin, leftProfit[i - 1]);
    // rightProfit[i] = max(rightMax - prices[i], rightProfit[i + 1]);
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 6ms
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> leftProfit(prices.size(), 0);
        vector<int> rightProfit(prices.size(), 0);
        int leftMin = prices[0];
        int rightMax = prices[prices.size() - 1];

        for (int i = 1; i < leftProfit.size(); ++i) {
            leftMin = min(leftMin, prices[i]);
            leftProfit[i] = max(prices[i] - leftMin, leftProfit[i - 1]);
        }

        for (auto i = static_cast<int>(prices.size() - 2); i >= 0; --i) {
            rightMax = max(rightMax, prices[i]);
            rightProfit[i] = max(rightMax - prices[i], rightProfit[i + 1]);
        }
        
        int result = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            result = max(result, leftProfit[i] + rightProfit[i]);
        }
        return result;
    }
};