/**
 * Problem: 376 Wiggle Subsequence  
 * Link: https://leetcode.com/problems/wiggle-subsequence/
 *
 * Approach:
 *   Maintain two DP states:
 *     - up:   length of the longest wiggle subsequence ending with an upward move
 *     - down: length of the longest wiggle subsequence ending with a downward move
 *
 *   For each element:
 *     - if nums[i] > nums[i-1], we extend the last downward subsequence → up = down + 1
 *     - if nums[i] < nums[i-1], we extend the last upward subsequence   → down = up + 1
 *     - if equal, no change (equal values cannot form a wiggle transition)
 *
 *   This DP relies on the fact that any wiggle (up/down) transition creates states
 *   that differ by at most 1, enabling O(n) time and O(1) space.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }

        int up = 1;   
        int down = 1; 

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } 
            else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
            
        }

        return max(up, down);
    }
};
