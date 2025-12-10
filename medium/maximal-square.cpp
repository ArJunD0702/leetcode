/**
 * Problem: 221 Maximal Square
 * Link: https://leetcode.com/problems/maximal-square/
 *
 * Approach:
 *   Use top-down DP with memoization. Define dp[i][j] as the side length of the largest
 *   square whose top-left corner is at cell (i, j). For each cell, recursively compute
 *   values for right, down, and diagonal neighbors. If the current cell contains '1',
 *   then dp[i][j] = 1 + min(right, down, diagonal); otherwise it is 0. Maintain a global
 *   maximum side length during recursion. The final answer is the square of this maximum.
 *
 * Time Complexity:  O(n * m)
 * Space Complexity: O(n * m)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(vector<vector<char>>& mat, int i, int j, int& mx, vector<vector<int>>& dp) {
    if (i >= mat.size() || j >= mat[0].size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int r = helper(mat, i, j + 1, mx, dp);
    int d = helper(mat, i + 1, j + 1, mx, dp);
    int l = helper(mat, i + 1, j, mx, dp);

    if (mat[i][j] == '1') {
        dp[i][j]= 1 + min({r, d, l});
        mx = max(mx, dp[i][j]);
        return dp[i][j];
    } 
    else {
        return dp[i][j] = 0;
    }
}

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int mx = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        helper(matrix, 0, 0, mx, dp);

        return mx * mx;
    }
};