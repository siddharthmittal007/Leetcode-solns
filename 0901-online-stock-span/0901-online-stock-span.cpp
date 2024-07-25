class StockSpanner {
public:
    stack<pair<int,int>> s;     // Monotonic decreasing stack of
                                // (price,day) pairs
    int day;

    StockSpanner() {
        day=0;
    }
    
    int next(int price) {
        // Popping upto previous greater price
        while(!s.empty() && s.top().first<=price)
        {
            s.pop();
        }
        int prev_gr_day=s.empty()?0:s.top().second;
        
        day++;
        s.push({price,day});    // Pushing current (price,day)
        
        return(day-prev_gr_day);       // Return stock span
    }
};

// T.C=O(N) ;   S.C=O(N)

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */