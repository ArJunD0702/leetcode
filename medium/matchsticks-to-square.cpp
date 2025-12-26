/**
 * Problem: 473 Matchsticks to Square
 * Link: https://leetcode.com/problems/matchsticks-to-square/
 *
 * Approach:
 *   Compute the total sum of matchsticks. If it is not divisible by 4,
 *   forming a square is impossible. Handle another simple case.
 *   Use DFS with backtracking to try assigning each matchstick to one of
 *   four partitions, ensuring no partition exceeds the target length.
 *   Place matchsticks one by one. if a placement leads to a valid completion,
 *   return true. Backtrack after each attempt to restore the partition state.
 *
 * Time Complexity: Exponential in n // not sure about this
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
bool dfs(int idx, vector<int>& matchsticks, vector<int>& bucket, int target) {
    if (idx == matchsticks.size()) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        if (bucket[i] + matchsticks[idx] > target) {
            continue;
        }

        bucket[i] += matchsticks[idx];
        if (dfs(idx + 1, matchsticks, bucket, target)) {
            return true;
        }
        bucket[i] -= matchsticks[idx];
        
        if (bucket[i] == 0) {
            break;
        }
    }

    return false;
}
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) {
            return false;
        }
        int target = sum / 4;
        for (int i = 0; i < n; i++) {
            if (matchsticks[i] > target) {
                return false;
            }
        }

        vector<int> bucket(4, 0);
        return dfs(0, matchsticks, bucket, target);
    }
};