/**
 * Problem: 733 Flood Fill
 * Link: https://leetcode.com/problems/flood-fill/
 *
 * Approach:
 *   Perform a DFS starting from the source cell (sr, sc).
 *   Store the original color and recolor all 4-directionally connected
 *   cells that have the same original color.
 *   Use a separate answer matrix to avoid modifying the input directly.
 *   Direction vectors are used to explore up, right, down, and left neighbors.
 *
 * Time Complexity:  O(m * n)
 * Space Complexity: O(m * n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, const vector<vector<int>>& image, int old, int color, vector<int>& drA, vector<int>& drB) {
        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();

        for (int i = 0; i < 4; i++) {
            int r = row + drA[i];
            int c = col + drB[i];

            if (r >= 0 && r < m && c >= 0 && c < n && image[r][c] == old && ans[r][c] != color) {
                dfs(r, c, ans, image, old, color, drA, drB);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        if (old == color) {
            return image;
        }

        vector<int> drA = {-1, 0, 1, 0};
        vector<int> drB = {0, 1, 0, -1};

        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, old, color, drA, drB);
        return ans;
    }
};