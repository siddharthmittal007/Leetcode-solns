class MyStack {
public:
    queue<int> q1;
    
    MyStack() {
    }
    
    void push(int x) {
        int k=q1.size();
        q1.push(x);                 // Place stack 'top' at queue 'back'
            
        for(int i=1;i<=k;i++)       // Bring stack 'top' to queue 'front'
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int temp=q1.front();    // stack 'top' at queue front
        q1.pop();
        return(temp);           // Returning 'top' element
    
    }
    
    int top() {
        return(q1.front());       // stack 'top' at queue front
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
// T.C=O(N) ;   S.C=O(1)

// POP
// T.C=O(1) ;   S.C=O(1)

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
