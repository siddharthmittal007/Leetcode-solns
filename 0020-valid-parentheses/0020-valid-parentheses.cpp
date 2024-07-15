class Solution {
public:
    // Utility function
    char openBracket(char c)
    {
        if(c==')')
        {
            return('(');
        }
        else if(c=='}')
        {
            return('{');
        }
        else    // (c==']')
        {
            return('[');
        }
    }
    
    bool isValid(string s) {
        stack<char> stk;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                stk.push(s[i]);
            }
            else if(stk.empty()==false && stk.top()==openBracket(s[i]))
            {
                stk.pop();
            }
            else
            {
                return(false);      // Invalid parenthesis
            }
        }

        return(stk.empty()==true);
    }
};