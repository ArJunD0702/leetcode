/**
 * Problem: 14 Longest Common Prefix
 * Link: https://leetcode.com/problems/longest-common-prefix/
 *
 * Approach:
 *   Sort the strings lexicographically. The LCP of the entire array
 *   must be the LCP of the first and last strings after sorting.
 *
 * Time Complexity:  O(n log n * L)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        sort(strs.begin(), strs.end());
        string a = strs.front();
        string b = strs.back();

        int i = 0;
        int n = min(a.size(), b.size());
        while (i < n && a[i] == b[i]) {
            i++;
        }

        return a.substr(0, i);
    }
};