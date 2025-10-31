// Problem: 49. Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/
// Time Complexity: O(n * m * logm)
// Memory Complexity: O(n * m)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (auto &word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto &group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};