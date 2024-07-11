class MedianFinder {
public:
    priority_queue<int> max_pq;                                 // Max Heap
    priority_queue<int,vector<int>,greater<int>> min_pq;        // Min Heap

    MedianFinder() {
    }
    
    void addNum(int num) 
    {
        if(max_pq.size()==0 && min_pq.size()==0)    // No elements
        {
            max_pq.push(num);
        }
        else if(max_pq.size()==min_pq.size())       // Heaps of equal size
        {
            if(min_pq.top()>=num)
            {
                max_pq.push(num);
            }
            else
            {
                max_pq.push(min_pq.top());
                min_pq.pop();
                min_pq.push(num);
            }
        }
        else                                        // Max Heap has greater size
        {
            if(num>=max_pq.top())
            {
                min_pq.push(num);
            }
            else
            {
                min_pq.push(max_pq.top());
                max_pq.pop();
                max_pq.push(num);   
            }
        }  
    }
    
    double findMedian() 
    {
        if(min_pq.size()==max_pq.size())                // Even elements
        {
            return((min_pq.top()+max_pq.top())/2.0);
        }
        else                                            // Odd elements
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
