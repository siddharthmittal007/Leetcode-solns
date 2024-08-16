class Solution {
public:
    // Utility function
    int pow(int base,int q,int exp)
    {
        if(exp==0)
            return(1);
        
        return((base*pow(base,q,exp-1))%q);
    }

    // Utility function
    bool check(string &haystack,string &needle,int pos)
    {
        for(int i=0;i<needle.size();i++)
        {
            if(haystack[i+pos]!=needle[i])
                return(false);
        }
        return(true);
    }
    
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())
            return(-1);
        
        // Rabin Karp
        int d=26,q=100000;
        int h=pow(d,q,needle.size());

        int p=0,t=0;
        for(int i=0;i<needle.size();i++)
        {
            p=(p*d+needle[i]-'a')%q;
            t=(t*d+haystack[i]-'a')%q;
        }

        for(int i=0;i<=(int)haystack.size()-(int)needle.size();i++)
        {
            cout<<p<<" "<<t<<" ";
            if(t==p && check(haystack,needle,i))
                return(i);      // Return first occurence of string
            
            if(i<(int)haystack.size()-(int)needle.size())
                t=(t*d+(haystack[i+needle.size()]-'a')-h*(haystack[i]-'a'))%q;
        }

        return(-1);     // 'needle' not a part of 'haystack'
    }
};

// T.C=O(N)    ;   S.C=O(N)
// RABIN KARP ALGORITHM
// PATTERN - STRING MATCHING