class Solution {
public:
    
    vector<string> ans; // To store possible sentences

    void backtrack(string& s,unordered_set<string>& ust,string& snt,int index)
    {
        if(index==s.size()) 
        {
            ans.push_back(snt); // Adding current sentence to solution
            return;
        }
        
        // Checking substrings starting 'index' for match with word in dictionary
        for(int i=index;i<s.size();i++)
        {
            if(ust.find(s.substr(index,i-index+1))!=ust.end())
            {
                int len=snt.length(); 
                // Appending word to sentence
                if(!snt.empty())
                {
                    snt+=" "; // Adding space
                }
                snt+=s.substr(index,i-index+1);
                backtrack(s,ust,snt,i+1);
            
                // Restoring to original string
                snt.erase(len);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // String to store current sentence
        string snt; 

        // Convert dictionary words to a set for O(1) lookup
        unordered_set<string> ust(wordDict.begin(),wordDict.end());
        
        // Start backtracking process
        backtrack(s,ust,snt,0); 
        
        return(ans);
    }
};