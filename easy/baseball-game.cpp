/**
 * Problem: 682 Baseball Game
 * Link: https://leetcode.com/problems/baseball-game/
 *
 * Approach:
 *   Use a stack to maintain the history of valid scores. Traverse the operations
 *   array once. For each operation: if it is "+", pop the top element to access
 *   the previous score, compute the sum of the last two scores, push back the
 *   popped value, and then push the new sum. If it is "D", push double of the
 *   current top. If it is "C", pop the top element to invalidate the last score.
 *   Otherwise, convert the string to an integer and push it. Maintain a running
 *   total sum that is updated during each operation.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (operations[i] == "+") {
                int first = st.top();
                st.pop();
                int newScore = first + st.top();
                st.push(first);
                st.push(newScore);
                sum += newScore;
            }
            else if (operations[i] == "D") {
                st.push(2 * st.top());
                sum += st.top();
            }
            else if (operations[i] == "C") {
                sum -= st.top();
                st.pop();
            }
            else {
                st.push(stoi(operations[i]));
                sum += st.top();
            }
        }

        return sum;
    }
};