/**
 * Problem: 222 Count Complete Tree Nodes
 * Link: https://leetcode.com/problems/count-complete-tree-nodes/
 *
 * Approach:
 *   Use the complete binary tree property.
 *   For each subtree:
 *     - Compute the height by moving leftmost.
 *     - Compute the height by moving rightmost.
 *   If both heights are equal, the subtree is a perfect binary tree and
 *   so the node count is (2^h - 1) directly.
 *   Otherwise, recurse on left and right subtrees and add 1 for the root.
 *
 * Time Complexity:  O((log n)^2)
 * Space Complexity: O(log n)
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
    int leftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int rightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return (1 + countNodes(root->left) + countNodes(root->right));
    }
};
