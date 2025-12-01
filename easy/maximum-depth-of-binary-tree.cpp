/**
 * Problem: 104 Maximum Depth of Binary Tree
 * Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 * Approach:
 *   Use recursive DFS. For each node, compute the depth of left and right
 *   subtrees and return max(left, right) + 1. Base case is a null node
 *   returning depth 0.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(h), h = height of tree 
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};