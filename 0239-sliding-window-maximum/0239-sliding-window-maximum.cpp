class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_sliding_window;     // Vector to store answer

        deque<int> q;                       // Monotonic decreasing queue

        for(int i=0;i<nums.size();i++)
        {
            // Enqueue
            while(!q.empty() && q.back()<nums[i])
            {
                q.pop_back();
            }
            q.push_back(nums[i]);

            // Store window max
            if(i>=k-1)
            {
                max_sliding_window.push_back(q.front());    
            }

            // Dequeue
            if(i>=k-1 && nums[i-k+1]==q.front())
            {
                q.pop_front();
            }
        }

        return(max_sliding_window);
    }
};

// T.C=O(N) ;   S.C=O(N)
// T.C OF BRUTE FORCE WOULD HAVE BEEN O(N*k)