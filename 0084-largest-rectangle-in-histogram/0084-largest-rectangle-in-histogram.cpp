class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;     
        stack<int> s;      // Monotonic increasing stack on bar heights

        // Traversing vector and adding elements to monotonic stacks 
        for(int i=0;i<=heights.size();i++)
        {
            while(!s.empty() && (i==heights.size() || heights[s.top()]>=heights[i]))
            {
                int ind=s.top();
                s.pop();
            
                int h=heights[ind];
                int w=s.empty()?i:i-s.top()-1;
                max_area=max(max_area,h*w);
            }
            s.push(i);
        }
        return(max_area);   // return max area
    }
};

// T.C=O(N) ;   S.C=O(N)
