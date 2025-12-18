/**
 * Problem: 210 Course Schedule II
 * Link: https://leetcode.com/problems/course-schedule-ii/
 *
 * Approach:
 *   Build an adjacency list where an edge goes from prerequisite to course, compute indegree
 *   for each course, and use Kahn’s algorithm.
 *   If all courses are processed, return the ordering.
 *   Otherwise, a cycle exists and no valid ordering is possible. 
 *
 * Time Complexity:  O(n + m), n is the number of courses and m the number of prereqs
 *
 * Space Complexity: O(n + m) (adjacency list, indegree array, queue, and result array)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
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

        vector<int> ans;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (auto it : adj[cur]) {
                in[it]--;
                if (in[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};