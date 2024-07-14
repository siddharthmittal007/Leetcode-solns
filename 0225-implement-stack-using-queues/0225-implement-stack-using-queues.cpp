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
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int temp=q2.front();
            q2.pop();
            return(temp);
        }
        else
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int temp=q1.front();
            q1.pop();
            return(temp);
        }
    }
    
    int top() {
        if(q1.size()==0)
        {
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int temp=q2.front();
            q2.pop();
            q1.push(temp);
            return(temp);
        }
        else
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int temp=q1.front();
            q1.pop();
            q2.push(temp);
            return(temp);
        }
    }
    
    bool empty() {
        if(q1.size()==0 && q2.size()==0)
        {
            return (true);
        }
        return(false);        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */