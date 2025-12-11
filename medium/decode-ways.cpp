/**
 * Problem: 91 Decode Ways
 * Link: https://leetcode.com/problems/decode-ways/
 *
 * Approach:
 *   Use 1D DP where dp[i] represents the number of ways to decode
 *   the prefix of length i. A single digit contributes dp[i-1] if it
 *   is not '0'. A valid two-digit number (10–26) contributes dp[i-2].
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
        }

        return dp[n];
    }
};