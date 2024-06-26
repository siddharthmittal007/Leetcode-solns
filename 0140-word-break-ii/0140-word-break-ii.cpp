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

    void backtrack(string& s,vector<string>& wordDict,string& currentSentence,int index)
    {
        if(index==s.size()) // Valid sentence
        {
            ans.push_back(currentSentence); // Adding currentSentence to solution
            return;
        }
        
        // Checking each word in dictionary if starting at 'index'
        for(int i=0;i<wordDict.size();i++)
        {
            if(checkWord(s,wordDict,i,index))
            {
                string originalSentence=currentSentence;    // Making a copy of
                                                            //  original string
                // Appending word to sentence
                if(!currentSentence.empty())
                {
                    currentSentence+=" "; // Adding space
                }
                currentSentence+=wordDict[i];

                backtrack(s,wordDict,currentSentence,index+wordDict[i].length());
            
                // Restoring to original string
                currentSentence=originalSentence;
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string currentSentence; 
        backtrack(s,wordDict,currentSentence,0); 
        return(ans);
    }
};