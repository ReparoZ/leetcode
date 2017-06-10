// Source: https://leetcode.com/problems/restore-ip-addresses/
// Author: ML3426
// Date: 2017-06-10

/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 * 
 * For example:
 * Given "25525511135",
 * 
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time: 3ms
    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses(s, 4);
    }
    
    vector<string> restoreIpAddresses(string s, int field) {
        if (field == 1) {
            if (s.length() != 1 && s[0] == '0') return {};
            int num = stoi(s);
            if (num < 256) return {s};
            else return {};
        }
        
        vector<string> res;

        for (int i = 0; i < 3; ++i) {
            if (s.length() - i - 1 > (field - 1) * 3 || s.length() - i - 1 < field - 1)
                continue;
            string prefix = s.substr(0, i + 1);
            if (prefix.length() != 1 && prefix[0] == '0') continue;
            int num = stoi(prefix);
            if (num > 255) continue;
            string suffix = s.substr(i + 1);
            vector<string> lastRes = restoreIpAddresses(suffix, field - 1);
            for (int j = 0; j < lastRes.size(); ++j) {
                res.push_back(prefix + "." + lastRes[j]);
            }
        }

        return res;
    }
};