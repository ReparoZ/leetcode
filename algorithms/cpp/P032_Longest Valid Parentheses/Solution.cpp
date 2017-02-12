// Source: https://leetcode.com/problems/longest-valid-parentheses/
// Author: ML3426
// Date: 2017-02-12

/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * 
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    // 动态规划法
    // 解释见https://leetcode.com/articles/longest-valid-parentheses/#approach-2-using-dynamic-programming-accepted
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 6ms
    int longestValidParentheses1(string s) {
        int maxLen = 0;
        if (s.length() < 2) return 0;

        int *dp = new int[s.length()]{0};
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 0) ? dp[i - dp[i - 1] - 2] + 2 : 2);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }

    // 栈方法
    // 解释见https://leetcode.com/articles/longest-valid-parentheses/#approach-3-using-stack-accepted
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 9ms
    int longestValidParentheses2(string s) {
        int maxLen = 0;
        stack<int> charStack;
        charStack.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                charStack.push(i);
            } else {
                charStack.pop();
                if (charStack.empty()) {
                    charStack.push(i);
                } else {
                    maxLen = max(i - charStack.top(), maxLen);
                }
            }
        }

        return maxLen;
    }

    // 遍历法
    // https://leetcode.com/articles/longest-valid-parentheses/#approach-4-without-extra-space-accepted
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 6ms
    int longestValidParentheses3(string s) {
        int left = 0, right = 0, maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxLength = max(maxLength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int) (s.length() - 1); i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxLength = max(maxLength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxLength;
    }
};