class StockSpanner {
public:
    stack<pair<int,int>> s;     // Monotonic decreasing stack of
                                // (price,day) pairs
    int day;

    StockSpanner() {
        day=0;
    }
    
    int next(int price) {
        day++;
        while(!s.empty() && s.top().first<=price)
        {
            s.pop();
        }

        int last=s.empty()?0:s.top().second;
        s.push({price,day});
        return(day-last);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */