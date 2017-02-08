// Source: https://leetcode.com/problems/valid-parentheses/
// Author: ML3426
// Date: 2017-02-08

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    // 利用栈结构进行括号的匹配
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 3ms
    bool isValid(string s) {
        stack<char> brackets;

        for (unsigned long i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                brackets.push(s[i]);
            } else if (brackets.size() == 0) {
                return false;
            }

            if (s[i] == ')') {
                if (brackets.top() == '(') {
                    brackets.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (brackets.top() == '[') {
                    brackets.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (brackets.top() == '{') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }

        return brackets.size() == 0;
    }
};