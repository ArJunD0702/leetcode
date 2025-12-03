#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    int mini = INT_MAX;
    stack<int> st;
public:
    MinStack() {
        stack<int> st;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if (val < mini) {
                st.push(2 * val - mini);
                mini = val;
            }
            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        int cur = st.top();
        st.pop();
        if (cur > mini) {
            
        }
        else {

        }
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */