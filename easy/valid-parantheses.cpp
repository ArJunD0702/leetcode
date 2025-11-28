/**
 * Problem: 20 Valid Parentheses
 * Link: https://leetcode.com/problems/valid-parentheses/
 *
 * Approach:
 *   Traverse the string once using a stack. Push opening brackets onto the
 *   stack. On encountering a closing bracket, check if the stack is empty.
 *   If the stack is empty, the string is invalid. Otherwise, pop the top and 
 *   verify that it correctly matches the current closing bracket. After 
 *   processing all characters, the string is valid only if the stack is empty.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty()) {
                    return false;
                }

                char t = st.top();
                if ((c == ')' && t != '(') ||
                    (c == '}' && t != '{') ||
                    (c == ']' && t != '[')) {
                        return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};