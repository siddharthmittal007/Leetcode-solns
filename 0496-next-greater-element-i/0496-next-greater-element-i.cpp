class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Hash table to store (elem,next_gr_elem) pairs
        unordered_map<int,int> ump; 

        // Monotonic decreasing stack
        stack<int> s;

        // Obtaining 'next greater element' for each element in 'nums2'
        for(int i=0;i<nums2.size();i++)
        {
            // Remove all elements smaller than 'current element' from stack
            // and save 'current element' as their 'next greater element'
            while(!s.empty() && s.top()<nums2[i])   
            {
                ump.insert({s.top(),nums2[i]});
                s.pop();
            }
            s.push(nums2[i]);       // Push 'current element' to stack
        }

        // No next 'greater element' for remaining elements in stack
        // Save '-1'
        while(!s.empty())
        {
            ump.insert({s.top(),-1});
            s.pop();
        } 


        vector<int> ans;        // To store answer
        // Obtaining 'next greater element' for each element in 'nums1'
        for(int i=0;i<nums1.size();i++)  
        {
            ans.push_back(ump.at(nums1[i]));
        }
        return(ans);
    }
};

// T.C=O(N+M)   ;   S.C=O(N)
// N->size of parent vector     ; M->size of subset vector