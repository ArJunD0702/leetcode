/**
 * Problem: 94 Binary Tree Inorder Traversal
 * Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *
 * Approach:
 *   Use depth-first search with recursion.
 *   For each node, recursively traverse the left subtree, then process the 
 *   current node, and finally traverse the right subtree. This follows the 
 *   LNR order required for inorder traversal. A helper function maintains 
 *   the traversal state and fills the result vector.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
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
    void helper(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }

        helper(root->left, ans);
        helper(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};