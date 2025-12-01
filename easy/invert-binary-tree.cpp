/**
 * Problem: 226 Invert Binary Tree
 * Link: https://leetcode.com/problems/invert-binary-tree/
 *
 * Approach:
 *   Perform DFS on the tree. At each node, swap the left and right child.
 *   Recursively apply the same operation to both subtrees.
 *   Base case is a null node returning null.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(h), h is the height of the tree
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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};