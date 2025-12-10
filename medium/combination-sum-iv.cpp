/**
 * Problem: 377 Combination Sum IV
 * Link: https://leetcode.com/problems/combination-sum-iv/
 *
 * Approach:
 *   Use 1D dynamic programming where dp[i] stores the number of ordered combinations
 *   that sum to i. Initialize dp[0] = 1. For each sum i from 1 to target, iterate over
 *   all numbers in nums and if i - nums[j] ≥ 0, add dp[i - nums[j]] to dp[i]. The answer
 *   is dp[target].
 *
 * Time Complexity:  O(n * target)
 * Space Complexity: O(target)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return (int)dp[target];
    }
};