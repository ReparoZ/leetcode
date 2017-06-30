// Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author: ML3426
// Date: 2017-06-30

/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 利用迭代法，每次选择中间的数字作为根节点，左右两边的数组作为左右子树的vector，再用同样的方法解出左右子树即可
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 12ms
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        
        int middle = int(nums.size() / 2);
        TreeNode *root = new TreeNode(nums[middle]);
        vector<int> leftVec(nums.begin(), nums.begin() + middle);
        vector<int> rightVec(nums.begin() + middle + 1, nums.end());
        root->left = sortedArrayToBST(leftVec);
        root->right = sortedArrayToBST(rightVec);
        return root;
    }
};