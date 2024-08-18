class Solution {
public:
    int pow(int base,int exp,int q)
    {
        int val=1;
        for(int i=1;i<=exp;i++)
        {
            val*=base;
            val%=q;
        }
        return(val);
    }

    bool check(string &a,string &b,int pos)
    {
        for(int i=0;i<b.size();i++)
        {
            if(a[(i+pos)%a.size()]!=b[i])
                return(false);
        }
        return(true);
    }
    
    int repeatedStringMatch(string a, string b) {

        int d=26,q=100007;
        int h=pow(d,b.size(),q);

        int p=0,t=0;
        for(int i=0;i<b.size();i++)
        {
            p=(p*d+(b[i]-'a'))%q;
            t=(t*d+(a[i%a.size()]-'a'))%q;
        }

        for(int i=0;i<a.size();i++)
        {
            if(t==p && check(a,b,i))
            {
                int reps=((i+b.size()-1)/a.size()) +1;
                return(reps);
            }

            t=(t*d+(a[(i+b.size())%a.size()]-'a')-h*(a[i]-'a'))%q;
            if(t<0)t+=q;
        }
        
        return(-1);
    }
};

// T.C=O(M+N)(AMORTIZED)   ;   S.C=O(1)
//RABIN KARP VARIANT
// PATTERN - STRING MATCHING 
