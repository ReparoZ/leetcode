// Source: https://leetcode.com/problems/simplify-path/
// Author: ML3426
// Date: 2017-02-24

/*
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用栈来保存path中的结点，用来处理"."和".."
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 6ms
    string simplifyPath(string path) {
        vector<string> pathStk;
        path += "/";
        
        string tempPath = "";
        for (int i = 0; i < path.length(); ++i) {
            if (path[i] == '/') {
                if (tempPath.length() == 0 || tempPath == ".");
                else if (tempPath == "..") { if (pathStk.size() > 0) pathStk.pop_back(); }
                else pathStk.push_back(tempPath);
                tempPath = "";
            } else tempPath += path[i];
        }
        
        string res;
        for (int i = 0; i < pathStk.size(); ++i) {
            res += ("/" + pathStk[i]);
        }
        
        return res.length() == 0 ? "/" : res;
    }
};