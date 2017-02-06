// Source: https://leetcode.com/problems/longest-common-prefix/
// Author: ML3426
// Date: 2017-02-06

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力解法优化版（水平搜索）
    // 先找出最短的字符串，因为前缀的长度肯定要小于最短的字符串，然后再将这个字符串作为原始字符串进行匹配
    // 从而找出公共前缀
    // 时间复杂度O(S)，空间复杂度为O(1)，S是集合中的字符个数
    // Time: 6ms
    string longestCommonPrefix1(vector<string> &strs) {
        int shortestIndex = findShortestString(strs);
        string initPrefix = shortestIndex == -1 ? "" : strs[findShortestString(strs)];

        for (int i = 0; i < strs.size(); ++i) {
            initPrefix = getCommonPrefix(initPrefix, strs[i]);
        }

        return initPrefix;
    }

    string getCommonPrefix(string s1, string s2) {
        string prefix = "";

        if (s1.length() > s2.length()) {
            return getCommonPrefix(s2, s1);
        }

        for (unsigned long i = 0; i < s1.length(); ++i) {
            if (s1[i] == s2[i]) {
                prefix += s1[i];
            } else {
                break;
            }
        }

        return prefix;
    }

    int findShortestString(vector<string> &strs) {
        unsigned long minLength = ULONG_MAX;
        int shortestString = -1;

        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].length() < minLength) {
                shortestString = i;
                minLength = strs[i].length();
            }
        }
        return shortestString;
    }

    // 暴力解法优化版（垂直搜索）
    // 先找出最短的字符串与第一个交换，因为前缀的长度肯定要小于最短的字符串，然后再针对这个字符串的每一个字符匹配整个字符串集合
    // 从而找出公共前缀
    // 时间复杂度O(S)，空间复杂度为O(1)，S是集合中的字符个数
    // Time: 9ms
    string longestCommonPrefix2(vector<string> &strs) {
        int shortestIndex = findShortestString(strs);
        if (shortestIndex == -1) return "";
        string commonPrefix = "";

        swap(strs[0], strs[shortestIndex]);
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) {
                    return commonPrefix;
                }
            }
            commonPrefix += strs[0][i];
        }
        return commonPrefix;
    }

    // 分治法
    // 将字符串拆分，拆分的结果集比较出公共前缀，再将比较出的结果比较出公共前缀
    // 时间复杂度为O(S)，空间复杂度为O(m*lg(n))，S是集合中的字符个数
    // Time: 12ms
    string longestCommonPrefix3(vector<string> &strs) {
        if (strs.size() == 0) return "";
        return longestCommonPrefix3(strs, 0, strs.size() - 1);
    }

    string longestCommonPrefix3(vector<string> &strs, unsigned long left, unsigned long right) {
        if (left == right) {
            return strs[left];
        }

        unsigned long mid = (left + right) / 2;
        string lcpLeft = longestCommonPrefix3(strs, left, mid);
        string lcpRight = longestCommonPrefix3(strs, mid + 1, right);
        return getCommonPrefix(lcpLeft, lcpRight);
    }

    // 二分搜索法。
    // 找到最短的字符串的长度，取一个字符串的前N位，看看前一半是不是公共前缀，如果是，则看看后一半是不是也属于公共前缀
    // 知道找到一个点，点前的字符全是公共前缀，而点后的字符都不属于公共前缀
    // 时间复杂度为O(S*lg(n))，空间复杂度为O(1)，S是集合中的字符个数
    // Time: 12ms
    string longestCommonPrefix4(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }

        auto shortestIndex = findShortestString(strs);
        auto minLen = strs[shortestIndex].size();
        unsigned long low = 1, high = minLen;

        while (low <= high) {
            auto middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle)) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }

        return strs[0].substr(0, (low + high) / 2);
    }

    bool isCommonPrefix(vector<string> &strs, unsigned long len) {
        string prefix = strs[0].substr(0, len);
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].length() < len) {
                return false;
            }

            for (int j = 0; j < prefix.length(); ++j) {
                if (strs[i][j] != prefix[j]) {
                    return false;
                }
            }
        }

        return true;
    }
};