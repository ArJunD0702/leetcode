/**
 * Problem: 98 Validate Binary Search Tree
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
 *
 * Approach:
 *   Use a recursive helper with lower and upper bounds to enforce the global
 *   BST property at every node. Each node’s value must lie strictly between
 *   the allowed range (l, h). For the left subtree, update the upper bound to
 *   the current node’s value; for the right subtree, update the lower bound.
 *   Using long long bounds prevents overflow at integer limits.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(h), where h is the height
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool helper(TreeNode* root, long long l, long long h) {
        if (!root) {
            return true;
        }

        if (root->val <= l || root->val >= h) {
            return false;
        }

        return (helper(root->left, l, root->val) && helper(root->right, root->val, h));
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};