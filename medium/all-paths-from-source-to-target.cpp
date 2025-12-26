/**
 * Problem: 797 All Paths From Source to Target
 * Link: https://leetcode.com/problems/all-paths-from-source-to-target/
 *
 * Approach:
 *   Use DFS with backtracking to enumerate all paths from node 0 to node n-1.
 *   Maintain a vector representing the current path. On reaching the target node, 
 *   record the current path. Backtrack after exploring each branch to allow divergence.
 *
 * Time Complexity:  O(n * (2 ^ n)) // not sure about this
 * Space Complexity: O(n) 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int src, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& res) {
        int n = graph.size();
        res.push_back(src);

        if (src == n - 1) {
            ans.push_back(res);
        }
        else {
            for (auto it : graph[src]) {
                dfs(it, graph, ans, res);
            }
        }

        res.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(0, graph, ans, res);
        return ans;
    }
};