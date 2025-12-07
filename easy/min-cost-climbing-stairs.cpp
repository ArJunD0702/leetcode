/**
 * Problem: 746 Min Cost Climbing Stairs
 * Link: https://leetcode.com/problems/min-cost-climbing-stairs/
 *
 * Approach:
 *   At each step i, the minimum cost to reach it is: dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
 *   Instead of maintaining a full dp array, only the previous two states are stored using variables
 *   `one` and `two`. The final answer is the minimum of the last two states since you can
 *   reach the top from either of the last two steps.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(vector<int>& cost, int n) {
        int one = cost[0];
        int two = cost[1];

        for (int i = 2; i < n; i++) {
            int three = min(one, two) + cost[i];
            one = two;
            two = three;
        }

        return min(one, two);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return helper(cost, n);
    }
};