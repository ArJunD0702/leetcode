/**
 * Problem: 450 Delete Node in a Binary Search Tree
 * Link: https://leetcode.com/problems/delete-node-in-a-bst/
 *
 * Approach:
 *   Recursively traverse the BST to locate the node with the target key.
 *   Once found, handle three structural cases:
 *   (1) Leaf node: delete and return nullptr.
 *   (2) One child: replace the node with its non-null child.
 *   (3) Two children: find the inorder successor (minimum in the right subtree),
 *       copy its value to the current node, and delete the successor recursively.
 *   A helper function is used to compute the minimum value in a subtree.
 *
 * Time Complexity:  O(h), where h is the height
 * Space Complexity: O(h) 
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
    int minVal(TreeNode* root) {
        TreeNode *cur = root;
        while (cur->left) {
            cur = cur->left;
        }

        return cur->val;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }

        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (!root->right) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else if (!root->left) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else {
                int mini = minVal(root->right);
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else {
            root->right = deleteNode(root->right, key);
            return root;
        } 
    }
};