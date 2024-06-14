class Solution {
public:
    vector<vector<string>> ans;

    bool checkPalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
            {
                return(false); // Not a palindrome
            }
        }
        return(true); // Palindrome
    }
    
    void backtrack(string& s,int ind,vector<string>& temp)
    {
        if(ind==s.length()) // Valid partitioning into palindromic substrings
        {
            ans.push_back(temp);
            return;
        }

        // Checking for possible palindromic substrings(starting index 'ind')
        for(int i=ind;i<s.length();i++)
        {
            if(checkPalindrome(s,ind,i))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                backtrack(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        backtrack(s,0,v);
        return(ans);
    }
};