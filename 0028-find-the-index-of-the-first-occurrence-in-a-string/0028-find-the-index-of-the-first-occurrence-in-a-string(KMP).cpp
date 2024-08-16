class Solution {
public:
    int strStr(string haystack, string needle) {
        // Combining strings 'needle' and 'haystack' with a unique seperator '#'
        string s(needle+'#'+haystack);
        
        // KMP 
        vector<int> lsp(s.size(),0);    // Longest Suffix Prefix(LSP) array
        lsp[0]=0;
        
        int q=0;
        for(int i=1;i<lsp.size();i++)
        {
            while(q>0 && s[i]!=s[q])
                q=lsp[q-1];

            if(s[i]==s[q])
                q++;
            
            lsp[i]=q;

            if(q==needle.size())
                return(i-(int)needle.size()*2);     // Return first occurence 
        }
    
        return(-1);     // 'needle' not a part of 'haystack'
    }
};

// T.C=O(N)    ;   S.C=O(N)
// KMP ALGORITHM
// PATTERN - STRING MATCHING
