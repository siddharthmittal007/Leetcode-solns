class Solution {
public:
    // Utility function
    void removeExtraSpace(string& s)
    {
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]==' ' && (j==0 || s[j-1]==' '))
                continue;
            s[i++]=s[j];
        }
        
        if(s[i-1]==' ')
            i--;
        
        s.erase(s.begin()+i,s.end());
    }

    // Utility function
    void reverse(string& s,int start,int end)
    {
        while(start<end)
        {
            swap(s[start++],s[end--]);
        }
    }
    
    string reverseWords(string s) {
        removeExtraSpace(s);

        int fwd1=0,fwd2=0;
        int bwd1=s.size()-1,bwd2=s.size()-1;

        while(fwd2<s.size()-1 && s[fwd2+1]!=' ')
            fwd2++;
        reverse(s,fwd1,fwd2);    
        
        while(bwd2>0 && s[bwd2-1]!=' ')
            bwd2--;
        reverse(s,bwd2,bwd1);

        
        while(fwd2<bwd2)
        {
            while(fwd1<=fwd2 && bwd2<=bwd1)
            {
                swap(s[fwd1++],s[bwd1--]);
            }

            if(fwd2<fwd1)
            {
                swap(s[fwd1++],s[bwd1--]);    // Adding space to reverse forming string
                
                if(fwd1==bwd2)      // Copy rest of word to forward forming string  
                {
                    reverse(s,bwd2,bwd1);
                    break;
                }
                fwd2=fwd1;
                while(fwd2!=s.size()-1 && s[fwd2+1]!=' ')
                    fwd2++;
                reverse(s,fwd1,fwd2);
            }

            if(bwd1<bwd2)
            {
                swap(s[fwd1++],s[bwd1--]);     // Adding space to reverse forming string
                
                if(bwd1==fwd2)      // Copy rest of word to forward forming string  
                {
                    reverse(s,fwd1,fwd2);
                    break;
                }
                bwd2=bwd1;
                while(bwd2!=0 && s[bwd2-1]!=' ')
                    bwd2--;
                reverse(s,bwd2,bwd1);
            }
        }

        return(s);
    }
};