// Source: https://leetcode.com/problems/anagrams/
// Author: ML3426
// Date: 2017-02-16

/*
 * Given an array of strings, group anagrams together.
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note: All inputs will be in lower-case.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 可以先对字符串排序，然后存储到hashmap里面。
    // 时间复杂度为O(NNLgN)，空间复杂度为O(N)
    // Time: 29ms
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> strMap;
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); ++i) {
            string strVal = strs[i];
            sort(strVal.begin(), strVal.end());

            strMap[strVal].push_back(strs[i]);
        }

        for (auto iter = strMap.begin(); iter != strMap.end(); ++iter) {
            res.push_back(iter->second);
        }

        return res;
    }
};