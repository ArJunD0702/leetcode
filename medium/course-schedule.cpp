/**
 * Problem: 207 Course Schedule
 * Link: https://leetcode.com/problems/course-schedule/
 *
 * Approach:
 *   Build an adjacency list from the prerequisites, compute indegree of 
 *   each node and use Kahn’s algorithm. Count how many nodes are processed.
 *   If all courses are processed, no cycle exists and all courses can be finished.
 *
 * Time Complexity:  O(n + m), n is the number of courses and m the number of prereqs
 *
 * Space Complexity: O(n + m) (adjacency list, indegree array, and queue)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> in(numCourses);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                in[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        int counter = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            counter++;

            for (auto it : adj[cur]) {
                in[it]--;
                if (in[it] == 0) {
                    q.push(it);
                }
            }
        }

        return counter == numCourses;
    }
};