class MinStack {
public:
    stack<int> s1;          // Normal stack
    stack<int> s2;          // Stack with minimum element on top

    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);       // Push element to normal stack
        if(s2.empty() || val<=s2.top())
        {
            s2.push(val);   // Update minmium element
        }
    }
    
    void pop() {
        // Pop element from normal stack 
        int temp=s1.top();  
        s1.pop();           
        
        // Pop if equal to minimum element from 's2'
        if(s2.top()==temp)
        {
            s2.pop();
        }
    }
    
    int top() {
        return(s1.top());
    }
    
    int getMin() {
        return(s2.top());
    }
};

// T.C=O(1) ALL OPERATIONS
// S.C=O(2*N)

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */