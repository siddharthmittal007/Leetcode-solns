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

    //Utility function
    int wordEnd(string& s,int pos)
    {
        while(pos<s.size()-1 && s[pos+1]!=' ')
        {
            pos++;
        }
        return(pos);
    }
    
    //Utility function
    int wordBegin(string& s,int pos)
    {
        while(pos>0 && s[pos-1]!=' ')
        {
            pos--;
        }
        return(pos);
    }
    
    string reverseWords(string s) {
        // Removing extra space
        removeExtraSpace(s);

        // If only one word
        if(wordEnd(s,0)==s.size()-1)
        {
            return(s);
        }

        int fwd1=0,fwd2=0;
        int bwd1=s.size()-1,bwd2=s.size()-1;

        // Reversing first and last words
        fwd2=wordEnd(s,fwd1);
        reverse(s,fwd1,fwd2);    
        
        bwd2=wordBegin(s,bwd1);
        reverse(s,bwd2,bwd1);

        
        // Reversing word order
        while(true)
        {
            while(fwd1<=fwd2+1 && bwd2-1<=bwd1)
            {
                swap(s[fwd1++],s[bwd1--]);
            }

            if(fwd2+1<fwd1)    
            {   
                if(fwd1==bwd2)       
                {
                    reverse(s,bwd2,bwd1);
                    break;
                }
                fwd2=wordEnd(s,fwd1);
                reverse(s,fwd1,fwd2);
            }

            if(bwd1<bwd2-1)
            {   
                if(bwd1==fwd2)
                {
                    reverse(s,fwd1,fwd2);
                    break;
                }
                bwd2=wordBegin(s,bwd1);
                reverse(s,bwd2,bwd1);
            }
        }

        return(s);
    }
};

// T.C=O(N) ;   S.C=O(1)