/**
 * Problem: 509 Fibonacci Number
 * Link: https://leetcode.com/problems/fibonacci-number/
 *
 * Approach:
 *   A dynamic programming solution with space optimization.
 *   Instead of maintaining a full DP array, only the previous two Fibonacci
 *   values are stored using rolling variables.
 *   For each i from 2 to n:
 *     - Compute F(i) = F(i-1) + F(i-2)
 *     - Shift the window forward by updating the two previous values
 *   This reduces space from O(n) to O(1) while maintaining linear time.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int prev1 = 0;
        int prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }

        return prev2;
    }
};