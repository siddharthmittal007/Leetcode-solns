class Solution {
public:
    string countAndSay(int n) {
        // Base Case
        if(n==1)
            return("1");

        // Recursive Call
        string s=countAndSay(n-1);
        
        // Finding RLE for input 'n' from RLE of 'n-1'
        string ans;

        int digit=s[0]-'0',pos=0;
        for(int i=0;i<=s.size();i++)
        {
            if(i==s.size() || s[i]-'0'!=digit)
            {
                ans.push_back('0'+(i-pos)); // Count
                ans.push_back('0'+digit);   // Character
                if(i<s.size())    
                {
                    pos=i;
                    digit=s[i]-'0';
                }
            }    
        }
        
        return(ans);
    }
};

// T.C=O(4^(N/3)) ;   S.C=O(4^(N/3)+O(N))(temporary string + Recursion stack)
// PROOF(LC EDITORIAL)  ;   BOUND NOT TIGHT

// IMP - HERE DIGITS TAKE ONLY THE VALUE 1,2,3
// THUS ANSWER STRINGS CAN BE COMPRESSED TO USE 2 BITS FOR EACH DIGIT IF
// SPACE OPTIMIZATION IN STORAGE OF STRING REQUIRED 