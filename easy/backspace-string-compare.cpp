/**
 * Problem: 844 Backspace String Compare
 * Link: https://leetcode.com/problems/backspace-string-compare/
 *
 * Approach:
 *   Use two separate stacks to simulate the typing process for both input
 *   strings. Traverse each string character by character. If the current
 *   character is not '#', push it onto the corresponding stack. If it is '#',
 *   pop the top element of the stack only if the stack is not empty. After
 *   processing both strings completely, compare the two stacks directly to
 *   determine if the final processed strings are identical.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stOne, stTwo;
        for (char c : s) {
            if (c == '#') {
                if (!stOne.empty()) {
                    stOne.pop();
                }
            }
            else {
                stOne.push(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!stTwo.empty()) {
                    stTwo.pop();
                }
            }
            else {
                stTwo.push(c);
            }
        }

        return (stOne == stTwo) ? true : false;
    }
};