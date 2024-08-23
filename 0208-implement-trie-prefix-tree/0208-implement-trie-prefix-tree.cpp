class TrieNode{
public:
    TrieNode* children[26];
    bool wordEnd;
    
    TrieNode(){
        wordEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
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
            int curr=word[i]-'a';
            if(temp->children[curr]==NULL)
                temp->children[curr]=new TrieNode();
            temp=temp->children[curr];
        }
        temp->wordEnd=true;
    }
    
    bool search(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.size();i++)
        {
            int curr=word[i]-'a';
            if(temp->children[curr]==NULL)
                return(false);  
            temp=temp->children[curr];
        }
        return(temp->wordEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            int curr=prefix[i]-'a';
            if(temp->children[curr]==NULL)
                return(false);  
            temp=temp->children[curr];
        }
        return(true);
    }
};

// T.C=O(N*26) ;  S.C=O(N*26) (FOR INSERT)
// T.C=O(N) ;   S.C=O(1) (FOR REST 2)

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */