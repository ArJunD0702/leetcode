/**
 * Problem: 409 Longest Palindrome
 * Link: https://leetcode.com/problems/longest-palindrome/
 *
 * Approach:
 *   Count the frequency of each character. For every character with frequency f, 
 *   use the maximum even contribution (f - f % 2) to form symmetric pairs.
 *   If at least one character has an odd frequency, place exactly
 *   one character in the center of the palindrome.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> m;
        for (char c : s) {
            m[c]++;
        }

        int ans = 0;
        for (auto x : m) {
            ans += x.second  - (x.second % 2);
        }
        int n = s.length();
        if (ans < n) {
            ans++;
        }

        return ans;
    }
};