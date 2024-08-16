class Solution {
public:
    void zFunction(vector<int> &z,string &s)
    {
        z[0]=0;
        int l=0,r=0;

        for(int i=1;i<z.size();i++)
        {
            if(i<r)
                z[i]=min(z[i-l],r-i);
            
            while(i+z[i]<s.size() && s[i+z[i]]==s[z[i]])
                z[i]++;
            
            if(i+z[i]>r)
            {
                l=i;
                r=i+z[i];
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        // Computing z function of 'needle'
        vector<int> z(needle.size(),0);
        zFunction(z,needle);

        // Finding first occurence of 'needle' in 'haystack'
        int l=0,r=0;
        for(int i=0;i<=(int)haystack.size()-(int)needle.size();i++)
        {
            int len=0;
            if(i<r)
                len=min(z[i-l],r-i);
            
            while(len<needle.size() && haystack[i+len]==needle[len])
                len++;
            
            if(len==needle.size())
                return(i);  // Return first occurence

            if(i+len>r)
            {
                l=i;
                r=i+len;
            }    
        } 
        return(-1);     // 'needle' not a part of 'haystack'
    }
};

// T.C=O(N)    ;   S.C=O(N)
// Z FUNCTION
// PATTERN - STRING MATCHING