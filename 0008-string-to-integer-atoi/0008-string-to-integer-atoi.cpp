class Solution {
public:
    // Utitlity function
    int readWhitespace(string& s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                return(i);
            }
        }
        return(0);
    }
    
    int myAtoi(string s) {
        // Ignoring leading whitespace
        int pos=readWhitespace(s);

        // Determining sign
        int sign=(pos<s.size() && s[pos]=='-'?-1:+1);
        if(pos<s.size() && s[pos]=='-' || s[pos]=='+')
            pos++;

        // Evaluating 
        long long value=0;
        for(int i=pos;i<s.size();i++)
        {
            int digit=s[i]-'0';
            
            if(digit<0 || digit>9)
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