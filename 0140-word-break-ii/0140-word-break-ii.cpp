class Solution {
public:
    
    vector<string> ans; // To store possible sentences

    void backtrack(string& s,unordered_set<string>& ust,vector<string>& v,int index)
    {
        if(index==s.size()) // Valid sentence
        {
            // Creating the sentence string 'snt'
            string snt;
            for(int i=0;i<v.size();i++)
            {
                snt.append(v[i]);
                snt.append(1,' ');
            }
            snt.pop_back();
            
            ans.push_back(snt); // Adding valid sentence to solution
            return;
        }
        
        // Checking substrings starting 'index' for match with word in dictionary
        for(int i=index;i<s.size();i++)
        {
            if(ust.count(s.substr(index,i-index+1)))
            {
                v.push_back(s.substr(index,i-index+1));
                backtrack(s,ust,v,i+1);
                v.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> v;               // To store words part of valid sentence
        
        unordered_set<string> ust;      // Unordered set to store words in dictionary
        for(int i=0;i<wordDict.size();i++)
        {
            ust.insert(wordDict[i]);
        }
        
        backtrack(s,ust,v,0); 
        return(ans);
    }
};