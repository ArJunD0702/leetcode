/**
 * Problem: 70 Climbing Stairs
 * Link: https://leetcode.com/problems/climbing-stairs/
 *
 * Approach:
 *   A space-optimized dynamic programming solution.
 *   The number of ways to reach step i depends on the sum of the ways to
 *   reach steps (i-1) and (i-2).
 *   Instead of using a full DP array, only the previous two states are
 *   maintained using rolling variables.
 *   For each step from 2 to n:
 *     - Compute current ways as prev1 + prev2
 *     - Shift the window by updating the previous values
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev1 = 1;
        
        for (int i = 2; i <= n; i++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};