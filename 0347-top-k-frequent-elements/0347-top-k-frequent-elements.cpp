class Solution {
public:
    // Custom Compare
    struct comp{
        bool operator()(pair<int,int> A,pair<int,int> B)
        {
            return(A.second<B.second);
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Inserting elements to unordered multiset
        unordered_multiset<int> ums;
        for(int i=0;i<nums.size();i++)
        {
            ums.insert(nums[i]);
        }

        // Max heap on key 'frequency' of elements
        typedef pair<int,int> pii;
        priority_queue<pii,vector<pii>,comp> pq;

        // Inserting (element,frequency) pairs to 'pq'
        for(auto itr=ums.begin();itr!=ums.end();)
        {
            int val=*itr;
            int cnt=ums.count(val);
            pq.push({val,cnt});
            
            // Moving iterator to next distinct element
            while(cnt)
            {
                itr++;
                cnt--;
            }
        }

        
        vector<int> ans;    // vector to store 'k' most frequent elements

        // Obtaining 'k' most frequent elements
        while(k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return(ans);        // Return 'k' most frequent elements
    }
};