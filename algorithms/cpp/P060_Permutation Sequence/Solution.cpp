// Source: https://leetcode.com/problems/permutation-sequence/
// Author: ML3426
// Date: 2017-02-19

/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ori = "123456789", res = "";
        vector<char> vec(ori.begin(), ori.begin() + n);
        --k;
        int totalNum = 1;
        for (int i = 1; i <= n; ++i) totalNum *= i;

        for (int i = n - 1; i > 0; --i) {
            int pos = k / (totalNum / (i + 1));
            res += vec[pos];
            vec.erase(vec.begin() + pos);
            k %= (totalNum / (i + 1));
            totalNum /= (i + 1);
        }

        return res += vec[0];
    }
};