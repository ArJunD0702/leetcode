/**
 * Problem: 785 Is Graph Bipartite?
 * Link: https://leetcode.com/problems/is-graph-bipartite/
 *
 * Approach:
 *   Use BFS-based 2-coloring. Maintain a color array initialized to -1.
 *   For every unvisited node, start BFS and assign an initial color.
 *   For each edge (u, nei), if nei is uncolored, assign it the opposite color of u.
 *   If nei is already colored and has the same color as u, the graph is not bipartite.
 *   Repeat for all connected components to handle disconnected graphs.
 *
 * Time Complexity:  O(N + E)
 * Space Complexity: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& colors) {
        colors[node] = 0;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto nei : graph[cur]) {
                if (colors[nei] == -1) {
                    colors[nei] = !colors[cur];
                    q.push(nei);
                }
                else if (colors[nei] == colors[cur]) {
                    return false;
                    
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!bfs(i, graph, colors)) {
                    return false;
                }
            }
        }

        return true;
    }
};