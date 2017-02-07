// Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: ML3426
// Date: 2017-02-07

/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    // 利用迭代的方式获取字符的全排列
    // 时间复杂度为O(3~4^N)，空间复杂度为O(1)
    // Time: 3ms
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapping = {
                {'0', ""},
                {'1', ""},
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };

        if (digits.size() == 0) {
            return {};
        }

        char next = digits[0];
        string nextDigits = digits.substr(1, digits.size() - 1);
        return letterCombinations(mapping, next, nextDigits);
    }

    vector<string> letterCombinations(unordered_map<char, string> &mapping, char first, string &digits) {
        vector<string> result;
        string letters = mapping[first];

        if (digits.length() != 0) {
            char next = digits[0];
            string nextDigits = digits.substr(1, digits.size() - 1);
            vector<string> lastResult = letterCombinations(mapping, next, nextDigits);
            for (int i = 0; i < letters.size(); ++i) {
                for (int j = 0; j < lastResult.size(); ++j) {
                    result.push_back(letters[i] + lastResult[j]);
                }
            }
        } else {
            for (int i = 0; i < letters.size(); ++i) {
                string a = "";
                a += letters[i];
                result.push_back(a);
            }
        }

        return result;
    }
};