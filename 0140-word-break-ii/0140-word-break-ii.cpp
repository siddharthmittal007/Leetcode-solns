class Solution {
public:
    
    vector<string> ans; // To store possible sentences

    bool checkWord(string& s,vector<string>& wordDict,int word,int index)
    {
        for(int i=0;i<wordDict[word].size();i++)
        {
            if(index+i==s.size() || s[index+i]!=wordDict[word][i])
            {
                return(false);
            }
        }
        return(true);
    }

    void backtrack(string& s,vector<string>& wordDict,vector<string>& v,int index)
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
        
        // Checking each word in dictionary if starting at 'index'
        for(int i=0;i<wordDict.size();i++)
        {
            if(checkWord(s,wordDict,i,index))
            {
                v.push_back(wordDict[i]);
                backtrack(s,wordDict,v,index+wordDict[i].length());
                v.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> v; // To store words part of valid sentence
        backtrack(s,wordDict,v,0); 
        return(ans);
    }
};