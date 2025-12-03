/**
 * Problem: 230 Kth Smallest Element in a BST
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 *
 * Approach:
 *   Use inorder traversal of the BST, which visits nodes in ascending order.
 *   Maintain a counter that increments on each node visit.
 *   When the counter reaches k, store the current node's value as the answer
 *   and terminate further traversal early to avoid unnecessary work.
 *
 * Time Complexity:  O(h + k), where h is the height
 * Space Complexity: O(h) due to recursion
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
    int cnt = 0;
    int ans = 0;

    void inorderTraversal(TreeNode* root, int k) {
        if (!root || cnt >= k) {
            return;
        }

        inorderTraversal(root->left, k);
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        inorderTraversal(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root, k);
        return ans;
    }
};