class Solution {
public:
    // Custom Compare
    struct comp{
        bool operator()(pair<int,int> A,pair<int,int> B)
        {
            return(A.second>B.second);
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Inserting elements to unordered map 
        // and maintaining frequency count of element
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]++;
        }

        // Min heap on key 'frequency' of elements
        typedef pair<int,int> pii;
        priority_queue<pii,vector<pii>,comp> pq;

        // Maintaining 'k' most frequent elements in 'pq'
        for (auto i:ump)
        {
            pq.push(i);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }   

        vector<int> ans;    // vector to store 'k' most frequent elements

        // Obtaining 'k' most frequent elements
        for(int i=1;i<=k;i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return(ans);        // Return 'k' most frequent elements
    }
};

// T.C=O(NLogK) ;   S.C=O(N)