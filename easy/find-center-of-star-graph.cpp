/**
 * Problem: 1791 Find Center of Star Graph
 * Link: https://leetcode.com/problems/find-center-of-star-graph/
 *
 * Approach:
 *   In a star graph, the center node has to appear in every edge.
 *   Compare the first two edges:
 *   - If edges[0][0] matches either endpoint of edges[1], it is the center.
 *   - Otherwise, edges[0][1] is the center.
 *
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        else {
            return edges[0][1];
        }
    }
};