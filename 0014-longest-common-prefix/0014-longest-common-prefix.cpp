class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Calculating max possible length of prefix
        size_t max_len=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            max_len=min(max_len,strs[i].size());
        }

        // LCP string
        string lcp;
        
        // Finding LCP
        for(int i=0;i<max_len;i++)
        {
            char c=strs[0][i];
            int j=1;
            for(;j<strs.size();j++)
            {
                if(strs[j][i]!=c)
                    break;
            }
            
            if(j!=strs.size())
                break;
            lcp+=c;
        }

        return(lcp);
      
    }
};