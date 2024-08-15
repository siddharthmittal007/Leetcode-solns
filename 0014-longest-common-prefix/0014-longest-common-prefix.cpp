class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp;
        
        // Finding LCP
        for(int i=0;i<strs[0].size();i++)
        {
            char c=strs[0][i];
            
            int j=1;
            while(j<strs.size() && i<strs[j].size() && c==strs[j][i])
                j++;
        
            if(j!=strs.size())
                break;
            
            lcp+=c;
        }

        return(lcp);
    }
};

// T.C=O(N*M)   ;   S.C=O(1)