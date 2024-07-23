class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_sliding_window;     // Vector to store answer

        queue<int> q;                       // Monotonic decreasing queue

        for(int i=0;i<nums.size();i++)
        {
            // Enqueue
            while(!q.empty() && q.back()<nums[i])
            {
                q.pop();
            }
            q.push(nums[i]);

            if(i>=k-1)
            {
                max_sliding_window.push_back(q.front());    // Store window max
            }

            // Dequeue
            if(i>=k-1 && nums[i-k+1]==q.front())
            {
                q.pop();
            }
        }

        return(max_sliding_window);
    }
};