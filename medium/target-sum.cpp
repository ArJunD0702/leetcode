/**
 * Problem: 494 Target Sum
 * Link: https://leetcode.com/problems/target-sum/
 *
 * Approach:
 *   Use bottom-up dynamic programming with state dp[i][rem],
 *   where dp[i][rem] represents the number of ways to assign
 *   + or - signs to elements from index i to the end such that
 *   the remaining sum required is rem. Since rem can be negative,
 *   shift all sums by an offset equal to the total sum of the array.
 *   The base case is dp[n][0] = 1 (encoded as dp[n][offset]).
 *   Fill the table backward from i = n-1 to 0 using the recurrence:
 *   dp[i][rem] = dp[i+1][rem - nums[i]] + dp[i+1][rem + nums[i]].
 *   The final answer is dp[0][target].
 *
 * Time Complexity:  O(n * S)
 * Space Complexity: O(n * S)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = accumulate(nums.begin(), nums.end(), 0);

        int rows = n + 1;
        int cols = 2 * offset + 1;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[n][offset] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                int ways  = 0;
                if (j - nums[i] >= 0) {
                    ways += dp[i + 1][j - nums[i]];
                }
                if (j + nums[i] < cols) {
                    ways += dp[i + 1][j + nums[i]];
                }

                dp[i][j] = ways;
            }
        }
        
        if (abs(target) > offset) {
            return 0;
        }
        return dp[0][target + offset];    
    }
};