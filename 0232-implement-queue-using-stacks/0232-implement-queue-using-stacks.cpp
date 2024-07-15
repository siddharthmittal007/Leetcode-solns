class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {     
    }
    
    void push(int x) {
        s1.push(x);             // Push to 's1'
    }
    
    int pop() {
        if(s2.size()==0)
        {
            // Tranferring elements from 's1' to 's2'
            while(s1.size()!=0)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int temp=s2.top();      // queue 'front' at 's2' top
        s2.pop();               // pop out queue 'front'
        return(temp);           // return 
    }
    
    int peek() {
        if(s2.size()==0)
        {
            // Tranferring elements from 's1' to 's2'
            while(s1.size()!=0)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }     
        return(s2.top());       // queue 'front' at 's2' top
        
    }
    
    bool empty() {
        if(s1.size()==0 && s2.size()==0)
        {
            return(true);       // Queue empty
        }
        return(false);          // Queue non-empty
        
    }
};


// PUSH
// T.C=O(1) ;   S.C=O(1)

// POP
// T.C=O(1) ;   S.C=O(1)

// AMORTIZED TIME COMPLEXITY OF OPERATIONS
// O(N) FOR N OPERATIONS I.E. PER OPERATION T.C=O(1)

// OVERALL SPACE COMPLEXITY
// O(N)

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */