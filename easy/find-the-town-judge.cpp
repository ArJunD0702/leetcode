/**
 * Problem: 997 Find the Town Judge
 * Link: https://leetcode.com/problems/find-the-town-judge/
 *
 * Approach:
 *   Use in-degree and out-degree counting. One hash table for each.
 *   For each trust pair (a, b), increment in-degree of b and out-degree of a.
 *   The town judge is the unique person with in-degree = n - 1 and out-degree = 0.
 *   If no such person exists, return -1.
 *
 * Time Complexity:  O(n + m)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> hashA(n + 1, 0); 
        vector<int> hashB(n + 1, 0); 

        int m = trust.size();
        for (int i = 0; i < m; i++) {
            hashA[trust[i][1]]++;
            hashB[trust[i][0]]++;
        }

        for(int i = 1; i <= n; i++) {
            if (hashA[i] == n - 1 && hashB[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};