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
        int value=0;
        for(;i<s.size();i++)
        {
            int digit=s[i]-'0';
            
            if(digit<0 || digit>9)  // Non-digit character encountered
                break;  
            
            // Avoiding integer overflow(positive)
            if(sign==1)
            {
                if(value>INT_MAX/10 || (value==INT_MAX/10 && digit>INT_MAX-value*10))
                {
                    value=INT_MAX;  // Rounding off
                    break;
                }
                value=value*10+digit;
            }
            // Avoiding integer overflow(negative)
            else
            {
                if  (value<INT_MIN/10 || 
                    (value==INT_MIN/10 && digit*sign<INT_MIN-value*10))
                {
                    value=INT_MIN;  // Rounding off
                    break;
                }
                value=value*10+digit*sign;
            }
        }
        return(value);
    }
};

// T.C=O(N)  ;   S.C=O(1)