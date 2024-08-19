class Solution {
public:
    bool isAnagram(string s, string t) {
        // Comparing size
        if(s.size()!=t.size())
            return(false);          // Not an anagram
        
        // Evaluating count of all characters in 's'
        vector<int> alphabetCount(26,0);
        for(int i=0;i<s.size();i++)
            alphabetCount[s[i]-'a']++;
        
        // Subtracting count of characters in 't'
        for(int i=0;i<t.size();i++)
        {
            if(alphabetCount[t[i]-'a']==0)
                return(false);      // Not an anagram
            alphabetCount[t[i]-'a']--;
        }

        // Checking if any character count non-zero
        for(int i=0;i<alphabetCount.size();i++)
        {
            if(alphabetCount[i]!=0)
                return(false);      // Not an anagram
        }

        return(true);               // 't' is anagram of 's'
    }
};

// T.C=O(N) ;   S.C=O(26) 