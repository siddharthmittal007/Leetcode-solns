class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int,vector<int>,greater<int>> min_pq; 

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_pq.size()==0)
        {
            max_pq.push(num);
        }
        else if(max_pq.size()==min_pq.size())
        {
            if(min_pq.top()>=num )
            {
                max_pq.push(num);
            }
            else
            {
                int temp=min_pq.top();
                min_pq.pop();
                min_pq.push(num);
                max_pq.push(temp);
            }
        }
        else
        {
            if(num>=max_pq.top())
            {
                min_pq.push(num);
            }
            else
            {
                int temp=max_pq.top();
                max_pq.pop();
                max_pq.push(num);
                min_pq.push(temp);
            }
        }
        
    }
    
    double findMedian() {
        if(min_pq.size()==max_pq.size())
        {
            return((min_pq.top()+max_pq.top())/2.0);
        }
        else
        {
            return(1.0*max_pq.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
