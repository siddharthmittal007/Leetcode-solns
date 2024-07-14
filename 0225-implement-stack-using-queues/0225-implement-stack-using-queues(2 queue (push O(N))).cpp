class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
    }
    
    void push(int x) {
        if(q1.size()==0)
        {
            q1.push(x);             // Place 'top' at queue front
            while(q2.size()!=0)     // Transfer all elements from 'q2' to 'q1'
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else    // (q2.size()==0)
        {
            q2.push(x);             // Place 'top' at queue front
            while(q1.size()!=0)     // Transfer all elements from 'q1' to 'q2'
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        if(q1.size()==0)
        {   
            int temp=q2.front();    // 'top' at queue front
            q2.pop();
            return(temp);           // Returning 'top' element
        }
        else
        {
            int temp=q1.front();    // 'top' at queue front
            q1.pop();
            return(temp);           // Returning 'top' element
        }
    }
    
    int top() {
        if(q1.size()==0)
        {
            return(q2.front());       // 'top' at queue front
        }
        else
        {
            return(q1.front());       // 'top' at queue front
        }
    }
    
    bool empty() {
        if(q1.size()==0 && q2.size()==0)
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
