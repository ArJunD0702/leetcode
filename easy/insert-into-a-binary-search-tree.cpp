/**
 * Problem: 701 Insert into a Binary Search Tree
 * Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
 *
 * Approach:
 *   If the tree is empty, create and return a new node as the root.
 *   Otherwise, iteratively traverse the BST starting from the root.
 *   At each step, move left if the value is smaller than the current node,
 *   or right otherwise. When a null child is found in the correct direction,
 *   insert the new node there. Finally, return the original root.
 *
 * Time Complexity:  O(h), where h is the height of the tree
 * Space Complexity: O(1)
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        TreeNode *cur = root;
        while (cur) {
            if (cur->val > val) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }

        
        return root;
    }
};