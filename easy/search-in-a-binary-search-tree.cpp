/**
 * Problem: 700 Search in a Binary Search Tree
 * Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
 *
 * Approach:
 *   Use the BST property to move left if the target is smaller than the current
 *   node value, and right if it is larger. Continue iteratively until the node
 *   is found or a null pointer is reached. This avoids recursion overhead and
 *   uses constant extra space.
 *
 * Time Complexity:  O(h), where h is the height of the tree
 * Space Complexity: O(1)
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (root->val == val) {
                return root;
            }
            root = (root->val > val) ? root->left : root->right;
        }

        return root;
    }
};