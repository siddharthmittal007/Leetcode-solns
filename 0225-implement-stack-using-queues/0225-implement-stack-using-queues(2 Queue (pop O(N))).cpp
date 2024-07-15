class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
    }
    
    void push(int x) {
        if(q1.size()==0)
        {
            q2.push(x);
        }
        else    // (q2.size()==0)
        {
            q1.push(x);
        }
    }
    
    int pop() {
        if(q1.size()==0)
        {   
            // Transferring all elements (except 'top' element) to 'q1'
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }

            int temp=q2.front();
            q2.pop();
            return(temp);   // Returning 'top' element
        }
        else
        {
            // Transferring all elements (except 'top' element) to 'q2'
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            
            int temp=q1.front();
            q1.pop();
            return(temp);   // Returning 'top' element
        }
    }
    
    int top() {
        if(q1.size()==0)
        {
            // Transferring all elements (except 'top' element) to 'q1'
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            
            int temp=q2.front();
            q2.pop();
            q1.push(temp);      // Transferring 'top' element
            return(temp);       // Return 'top' element
        }
        else
        {
            // Transferring all elements (except 'top' element) to 'q2'
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            
            int temp=q1.front();
            q1.pop();
            
            q2.push(temp);      // Transferring 'top' element
            return(temp);       // Return 'top' element
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
// T.C=O(1) ;   S.C=O(1)

// POP
// T.C=O(N) ;   S.C=O(1)

// OVERALL S.C=O(N)

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
