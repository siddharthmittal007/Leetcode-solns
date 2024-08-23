class TrieNode{
public:
    vector<TrieNode*> children;
    bool wordEnd;
    
    TrieNode(){
        children=vector<TrieNode*>(26,NULL);
        wordEnd=false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            if(temp->children[c-'a']==NULL)
                temp->children[c-'a']=new TrieNode();
            temp=temp->children[c-'a'];
        }
        temp->wordEnd=true;
    }
    
    bool search(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            if(temp->children[c-'a']==NULL)
                return(false);  // Word not found
            temp=temp->children[c-'a'];
        }
        return(temp->wordEnd?true:false);
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            char c=prefix[i];
            if(temp->children[c-'a']==NULL)
                return(false);  // Prefix not found
            temp=temp->children[c-'a'];
        }
        return(true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */