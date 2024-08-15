class Solution {
public:
    int myAtoi(string s) {
        // Ignoring leading whitespace
        int i=0;
        while(i<s.size() && s[i]==' ')
            i++;

        // Determining sign
        int sign=(i<s.size() && s[i]=='-'?-1:+1);
        if(i<s.size() && s[i]=='-' || s[i]=='+')
            i++;

        // Evaluating 
        long long value=0;
        for(;i<s.size();i++)
        {
            int digit=s[i]-'0';
            
            if(digit<0 || digit>9)  // Non-digit character encountered
                break;  
            
            value=10*value+digit*sign;
            
            // Rounding
            if(value>=INT_MAX || value<=INT_MIN)
            {
                value=value>=INT_MAX?INT_MAX:INT_MIN;
                break;
            }   
        }
        return(value);
    }
};

// T.C=O(N)  ;   S.C=O(1)