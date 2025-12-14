/**
 * Problem: 547 Number of Provinces
 * Link: https://leetcode.com/problems/number-of-provinces/
 *
 * Approach:
 *   Treat the adjacency matrix as an undirected graph. Maintain a visited array 
 *   to track explored cities. For each unvisited city, perform DFS to mark all
 *   cities in its connected component. Each DFS call corresponds to one province.
 *
 * Time Complexity:  O(n ^ 2)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i, int n, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[i] = 1;
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && !vis[j]) {
                dfs(j, n, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, n, isConnected, vis);
            }
        }

        return ans;
    }
};