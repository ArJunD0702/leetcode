/**
 * Problem: 1047 Remove All Adjacent Duplicates in String
 * Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 *
 * Approach:
 *   Use a stack to process the string character by character. Traverse the input
 *   string once. If the current character matches the top of the stack, pop the
 *   top element to remove the adjacent duplicate. Otherwise, push the character
 *   onto the stack. After processing all characters, rebuild the resulting
 *   string by popping all elements from the stack into a string and reverse it
 *   to restore the correct order.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s) {
            if ((!st.empty()) && c == st.top()) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        s.clear();
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};