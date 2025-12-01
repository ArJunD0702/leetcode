/**
 * Problem: 101 Symmetric Tree
 * Link: https://leetcode.com/problems/symmetric-tree/
 *
 * Approach:
 *   Recursively compare left and right subtrees as mirror images.
 *   For each pair of nodes:
 *     - If both are null → symmetric.
 *     - If one is null or values differ → not symmetric.
 *     - Recurse on (left of first, right of second) and
 *       (right of first, left of second).
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(h)
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
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
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (!l && !r) {
            return true;
        }
        else if (!l || !r) {
            return false;
        }
        else if (l->val != r->val) {
            return false;
        }

        return (isMirror(l->left, r->right) && isMirror(l->right, r->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};