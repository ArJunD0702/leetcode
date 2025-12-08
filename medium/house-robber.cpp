/**
 * Problem: 198 House Robber
 * Link: https://leetcode.com/problems/house-robber/
 *
 * Approach:
 *   This is a space-optimized 1D dynamic programming solution.
 *   Let dp[i] represent the maximum amount that can be robbed from houses
 *   in the range [0..i] with the constraint that no two adjacent houses
 *   can be robbed.
 *   The recurrence is:
 *     dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 *   Instead of storing the full dp array, only two rolling variables are
 *   maintained to represent dp[i-1] and dp[i-2], achieving O(1) space.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int cur = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};