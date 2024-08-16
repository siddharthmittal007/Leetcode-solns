class Solution {
public:
    int strStr(string haystack, string needle) {
        // Combining strings 'needle' and 'haystack' with a unique seperator '#'
        string s(needle+'#'+haystack);
        
        // Z function
        vector<int> z(s.size(),0);
        z[0]=0;
        int l=0,r=0;

        for(int i=1;i<z.size();i++)
        {
            if(i<r)
                z[i]=min(z[i-l],r-i);
            
            while(i+z[i]<s.size() && s[i+z[i]]==s[z[i]])
                z[i]++;
            
            if(z[i]==needle.size())
                return(i-(int)needle.size()-1);     // Return first occurence 

            if(i+z[i]>r)
            {
                l=i;
                r=i+z[i];
            }
        }
    
        return(-1);     // 'needle' not a part of 'haystack'
    }
};

// T.C=O(N)    ;   S.C=O(N)
// Z FUNCTION
// PATTERN - STRING MATCHING
