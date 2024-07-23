typedef pair<int,pair<int,int>> elem;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;     
        stack<elem> s;      // Monotonic increasing stack of
                            // (ind,(height,prev_ind)) elements

        // Traversing vector and adding elements to monotonic stacks 
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && s.top().second.first>=heights[i])
            {
                // Update max area on elem pop
                int ht=s.top().second.first,prev_ind=s.top().second.second;        
                max_area=max(max_area,(i-prev_ind)*ht);
                s.pop();
            }
            // Push current element
            if(s.empty())
            {
                s.push(make_pair(i,make_pair(heights[i],0)));
            }
            else
            {
                s.push(make_pair(i,make_pair(heights[i],s.top().first+1)));
            }  
        }

        // Empty stack iteratively and update max area value
        int n=heights.size();
        while(!s.empty())
        {
            int ht=s.top().second.first,prev_ind=s.top().second.second;  
            max_area=max(max_area,(int)((n-prev_ind)*ht));
            s.pop();
        }
        
        return(max_area);   // return max area
    }
};

// T.C=O(N) ;   S.C=O(N)
