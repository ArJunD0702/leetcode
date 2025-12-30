/**
 * Problem: 316 Remove Duplicate Letters
 * Link: https://leetcode.com/problems/remove-duplicate-letters/
 *
 * Approach:
 *   First record the last occurrence index of each character.
 *   Traverse the string left to right: If the current character is already
 *   used, skip it. Otherwise, while the stack top is lexicographically larger
 *   than the current character and the stack top appears again later, pop it 
 *   and mark it unused. Push the current character and mark it used.
 *   Finally, reverse the stack to obtain the result.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> visited(26);
        stack<char> st;
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';
            if (visited[cur]) {
                continue;
            }

            while (!st.empty() && st.top() > s[i] && last[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            visited[cur] = 1;
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};