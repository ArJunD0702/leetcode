/**
 * Problem: 1827 Minimum Operations to Make the Array Increasing
 * Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
 *
 * Approach:
 *   For each index i (i >= 1), ensure nums[i] > nums[i-1].
 *   If nums[i] <= nums[i-1], increment nums[i] to nums[i-1] + 1.
 *   Accumulate the total increments applied as the answer.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                int cost = nums[i - 1] - nums[i] + 1;
                nums[i] += cost;
                ans += cost;
            }
        }

        return ans;
    }
};