/**
 * Problem: 279 Perfect Squares
 * Link: https://leetcode.com/problems/perfect-squares/
 *
 * Approach:
 *   Use 1D dynamic programming where dp[i] stores the minimum number of perfect squares
 *   needed to form sum i. Initialize dp[0] = 0 and for each i from 1 to n, try all square
 *   numbers j*j ≤ i and update dp[i] = min(dp[i], dp[i - j*j] + 1). The final answer is dp[n].
 *
 * Time Complexity:  O(n * sqrt(n))
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int r = floor(sqrt(n));
        if (r * r == n) {
            return 1;
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};