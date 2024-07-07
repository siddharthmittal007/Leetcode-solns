class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;    // Min Heap

        // Adding all elements to the heap
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        // Removing elements before kth largest
        while(pq.size()>k)
        {
            pq.pop();
        }

        return(pq.top());       // return kth largest
    }
};
