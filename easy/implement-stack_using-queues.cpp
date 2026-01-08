/**
 * Problem: 225 Implement Stack using Queues
 * Link: https://leetcode.com/problems/implement-stack-using-queues/
 *
 * Approach:
 *   Use two queues with a costly-push strategy.
 *   Maintain the invariant that queue p always represents the stack,
 *   with its front as the stack top.
 *
 *   On push(x), push x into the empty queue q, move all elements from p to q
 *   and then swap p and q. This ensures the most recently pushed element is always
 *   at the front of p, making pop() and top() O(1).
 *
 * Time Complexity:
 *   push: O(n)
 *   pop:  O(1)
 *   top:  O(1)
 *
 * Space Complexity:
 *   O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> p;
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        while (!p.empty()) {
            q.push(p.front());
            p.pop();
        }

        swap(p, q);
    }
    
    int pop() {
        int x = p.front();
        p.pop();
        return x;
    }
    
    int top() {
        return p.front();
    }
    
    bool empty() {
        return p.empty();
    }
};
