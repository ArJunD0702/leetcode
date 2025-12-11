/**
 * Problem: 300 Longest Increasing Subsequence
 * Link: https://leetcode.com/problems/longest-increasing-subsequence/
 *
 * Approach:
 *   Classic O(n^2) DP.
 *   Define dp[i] as the length of the longest increasing subsequence ending at index i.
 *   Initialize dp[i] = 1 for all i (every element alone forms a subsequence of length 1).
 *
 *   For each i from 0..n-1:
 *       For each j from 0..i-1:
 *           If nums[i] > nums[j], then nums[i] can extend the subsequence ending at j.
 *           Update dp[i] = max(dp[i], dp[j] + 1).
 *
 *   The answer is the maximum value in dp[].
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
