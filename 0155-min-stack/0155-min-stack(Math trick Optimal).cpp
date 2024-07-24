class MinStack {
public:
    stack<int> s;         
    int min_val;
    
    MinStack() {

    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            min_val=val;
            return;
        }

        if(min_val<=val)
        {
            s.push(val);
        }
        else
        {
            s.push(val-min_val+val);
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
            min_val=min_val-s.top()+min_val;
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
