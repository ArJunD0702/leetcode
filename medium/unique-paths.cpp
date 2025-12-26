/**
 * Problem: 62 Unique Paths
 * Link: https://leetcode.com/problems/unique-paths/
 *
 * Approach:
 *   Use dynamic programming where dp[i][j] represents the number of ways
 *   to reach cell (i, j) from the start.
 *   Initialize the first row and first column to 1 since there is only
 *   one way to move straight right or straight down.
 *   The final answer is stored at dp[m-1][n-1].
 *
 * Time Complexity:  O(m * n)
 * Space Complexity: O(m * n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};