class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()){
            st.push(val);
            minSt.push(val);
        }
    }
    
    void pop() {
        int x = st.top(); st.pop();
        if(minSt.size() && x == minSt.top()){
            minSt.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(minSt.size())return minSt.top();
        else return INT_MAX;
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