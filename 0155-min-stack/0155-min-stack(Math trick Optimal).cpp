class MinStack {
public:
    stack<long long> s;         
    long long min_val;
    
    MinStack() {
        min_val=INT_MAX;
    }
    
    void push(int val) {
        if(min_val<=val)
        {
            s.push(val);
        }
        else
        {
            s.push(val*2LL-min_val);
            min_val=val;
        }
    }
    
    void pop() {
        if(min_val<=s.top())         
        {
            s.pop();
        }
        else
        {
            min_val=2*min_val-s.top();
            s.pop();
        }
    }
    
    int top() {
        if(min_val<=s.top())
        {
            return(s.top());
        }
        else
        {
            return(min_val);
        }
    }
    
    int getMin() {
        return(min_val);
    }
};

// T.C=O(1) ALL OPERATIONS
// S.C=O(N)

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
