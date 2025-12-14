/**
 * Problem: 200 Number of Islands
 * Link: https://leetcode.com/problems/number-of-islands/
 *
 * Approach:
 *   Treat the grid as a graph where each cell is a node.
 *   Iterate over all cells, and when an unvisited land cell is found,
 *   it represents a new island. Increment the count and run BFS from
 *   that cell to mark all 4-directionally connected land cells as visited.
 *   BFS ensures the entire connected component is covered before continuing
 *   the scan.
 *
 * Time Complexity:  O(n * m)
 * Space Complexity: O(n * m)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();

            for (int k = 0; k < 4; k++) {
                int R = r + dr[k];
                int C = c + dc[k];

                if (R >= 0 && R < n && C >= 0 && C < m &&
                    grid[R][C] == '1' && !vis[R][C]) {
                    vis[R][C] = 1;
                    q.push({R, C});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    ans++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return ans;
    }
};