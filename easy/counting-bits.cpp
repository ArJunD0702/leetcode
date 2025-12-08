/**
 * Problem: 338 Counting Bits
 * Link: https://leetcode.com/problems/counting-bits/
 *
 * Approach:
 *   Let dp[i] represent the number of set bits in the binary form of i.
 *   For any i > 0:
 *     - Right shifting i by 1 removes the least significant bit.
 *     - The count of set bits in i equals the count in (i >> 1) plus
 *       the value of the least significant bit (i & 1).
 *   Thus the recurrence is:
 *     dp[i] = dp[i >> 1] + (i & 1)
 *   The table is filled bottom-up from 0 to n.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};