/**
 * Problem: 1971 Find if Path Exists in Graph
 * Link: https://leetcode.com/problems/find-if-path-exists-in-graph/
 *
 * Approach:
 *   - Convert the given edge list into an adjacency list since DFS requires
 *     direct access to neighbors of a node.
 *   - Perform a DFS starting from source.
 *   - If the current node equals destination, a valid path exists.
 *   - Recursively explore all unvisited neighbors and stop as soon
 *     as the destination is reached.
 *
 * Time Complexity:  O(n + m), where n is number of the nodes and m is the number of edges
 *
 * Space Complexity: O(n + m) (adjacency list storage + visited array + recursion stack)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(vector<int>& vis, vector<vector<int>>& adj, int source, int destination) {
        if (source == destination) {
            return true;
        }

        vis[source] = 1;
        for (auto nei : adj[source]) {
            if (!vis[nei]) {
                if (dfs(vis, adj, nei, destination)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n);
        
        vector<vector<int>> adj(n);
        for (vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(vis, adj, source, destination);
    }
};