class MyStack {
public:
    queue<int> q1;
    
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);      
    }
    
    int pop() {
        // Bringing stack 'top' to queue front 
        for(int i=1;i<=q1.size()-1;i++)        
        {
            q1.push(q1.front());
            q1.pop();
        }

        int temp=q1.front();
        q1.pop();
        return(temp);           // Return stack 'top'
    }
    
    int top() {
        // Bringing stack 'top' to queue front 
        for(int i=1;i<=q1.size()-1;i++)        
        {
            q1.push(q1.front());
            q1.pop();
        }
        
        int temp=q1.front();
        q1.pop();
        q1.push(temp);
        return(temp);           // Return stack 'top'
    }
    
    bool empty() {
        if(q1.size()==0)
        {
            return (true);  // Stack empty
        }
        return(false);      // Stack non-empty     
    }
};

// PUSH
// T.C=O(1) ;   S.C=O(1)

// POP
// T.C=O(N) ;   S.C=O(1)

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
