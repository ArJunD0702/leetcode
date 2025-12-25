/**
 * Problem: 1334 Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 *
 * Approach:
 *   Use Floyd–Warshall to compute all-pairs shortest paths. Initialize a distance 
 *   matrix with INF for non-edges and 0 on the diagonal.
 *   After computing shortest distances, for each city count how many other cities
 *   are reachable within the given distance threshold.
 *   Track the city with the minimum reachable count. In case of ties, choose the
 *   city with the larger index.
 *
 * Time Complexity:  O(n ^ 3)
 * Space Complexity: O(n ^ 2)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void floydWarshall(vector<vector<int>>& dist) {
        int n = dist.size();
        const int INF = 1e9;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j],
                                          dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto& it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        floydWarshall(dist);

        int ans = -1;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            if (cnt < mn || (cnt == mn && i > ans)) {
                mn = cnt;
                ans = i;
            }
        }

        return ans;
    }
};
