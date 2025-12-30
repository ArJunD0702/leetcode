/**
 * Problem: 452 Minimum Number of Arrows to Burst Balloons
 * Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 *
 * Approach:
 *   Sort all balloons by their ending coordinate. Maintain the position of the current arrow.
 *   Traverse the balloons in sorted order: If this is the first balloon, or its start is 
 *   greater than the current arrow position, shoot a new arrow at this balloon’s end.
 *   Otherwise, the current arrow already bursts this balloon.
 *
 * Time Complexity:  O(n log n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int n = points.size();
        int ans = 0, arrow = 0;
        for (int i = 0; i < n; i++) {
            if (ans == 0 || points[i][0] > arrow) {
                ans++;
                arrow = points[i][1];
            }
        }

        return ans;
    }
};