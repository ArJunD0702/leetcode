/**
 * Problem: 144 Binary Tree Preorder Traversal
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
 *
 * Approach:
 *   Use Depth First Search (DFS) recursion with a helper function. Start from
 *   the root, and for each node, first process the current node (store its
 *   value), then recursively traverse the left subtree, followed by the right
 *   subtree. A reference vector is passed to the helper function to store the
 *   traversal result, and the main function returns this vector after DFS
 *   completes.
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
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }

        ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};