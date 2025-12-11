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
        int prev2 = 1;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int cur = 0;
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                cur += prev2;
            }
            if (s[i - 1] != '0') {
                cur += prev1;
            }
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};