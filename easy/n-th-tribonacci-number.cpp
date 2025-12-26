/**
 * Problem: 1137 N-th Tribonacci Number
 * Link: https://leetcode.com/problems/n-th-tribonacci-number/
 *
 * Approach:
 *   Handle base cases for n = 0, 1, 2 directly. Use an iterative bottom-up dynamic
 *   programming approach. Update the rolling variables to compute the next 
 *   Tribonacci number.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        else if (n == 2) {
            return 1;
        }

        int prev3 = 0, prev2 = 1, prev1 = 1;
        for (int i = 3; i <= n; i++) {
            int cur = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};