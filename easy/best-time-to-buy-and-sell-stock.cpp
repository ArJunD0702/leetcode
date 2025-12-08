/**
 * Problem: 121 Best Time to Buy and Sell Stock
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Approach:
 *   A dynammic programming solution.
 *   For each day i:
 *     - Update the minimum buying price using prices[i]
 *     - Compute the profit if selling on day i
 *     - Update the global maximum profit accordingly
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyPrice = prices[0];
        int profit = 0;
        int n = prices.size();

        for (int i = 1; i < n; i++) {
            minBuyPrice = min(minBuyPrice, prices[i]);
            profit = max(profit, prices[i] - minBuyPrice);
        }

        return profit;
    }
};