/**
 * Problem: 322 Coin Change (Minimum Coins)
 * Link: https://leetcode.com/problems/coin-change/
 *
 * Approach:
 *   Use 1D dynamic programming where dp[i] represents the minimum number of coins
 *   needed to make sum i. Initialize dp[0] = 0 and all other dp[i] to INT_MAX to
 *   denote unreachable states. For each amount i from 1 to the target amount,
 *   iterate over all coin denominations. If i - coin >= 0 and dp[i - coin] is
 *   reachable, update dp[i] as:
 *       dp[i] = min(dp[i], dp[i - coin] + 1)
 *
 * Time Complexity:  O(amount * numberOfCoins)
 * Space Complexity: O(amount)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        int n = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if ((i - coins[j] >= 0) && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};