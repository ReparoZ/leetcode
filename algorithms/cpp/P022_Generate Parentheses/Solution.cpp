// Source: https://leetcode.com/problems/generate-parentheses/
// Author: ML3426
// Date: 2017-02-09

/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用一个Pair来保存字符串的相关信息以免每一次都需要计算
    // Pair的first是生成的字符串的本体，pair的right保存着当前字符串的左括号个数和可以放置的右括号的个数
    // 时间复杂度为O(N^2)，空间复杂度为O(N^2)
    // Time: 3ms
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};
        vector<pair<string, pair<int, int>>> res;
        res.push_back({"(", {1, 1}});

        for (int i = 0; i < 2 * n - 1; ++i) {
            vector<pair<string, pair<int, int>>> tempRes;
            for (int j = 0; j < res.size(); ++j) {
                auto elem = res[j];
                if (elem.second.first < n) {
                    string left = elem.first;
                    left += "(";
                    tempRes.push_back({left, {elem.second.first + 1, elem.second.second + 1}});
                }
                
                if (elem.second.second > 0) {
                    string left = elem.first;
                    left += ")";
                    tempRes.push_back({left, {elem.second.first, elem.second.second - 1}});
                }
            }
            res = tempRes;
        }

        vector<string> result;
        for (int i = 0; i < res.size(); ++i) {
            result.push_back(res[i].first);
        }

        return result;
    }
};