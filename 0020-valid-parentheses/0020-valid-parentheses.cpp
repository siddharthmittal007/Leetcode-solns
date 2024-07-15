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
                stk.push(s[i]);     // Push opening bracket
            }
            else if(stk.empty()==false && stk.top()==openBracket(s[i]))
            {
                stk.pop();          // Pop out matching opening bracket
            }
            else        // 'Closing bracket' mismatch with last open 'opening bracket'
            {
                return(false);      // Invalid parenthesis
            }
        }

        return(stk.empty()==true);  // Valid parenthesis if stack empty,
                                    // else invalid(Unclosed open brackets)
    }
};