class Node{
public:    
    Node* links[2];

    Node(){
        links[0]=links[1]=NULL;
    }
};

class Trie{
public:    
    Node *root;

    Trie(){
        root=new Node();
    }

    // To insert binary representation of given number to trie
    void insert(int value)
    {
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(value>>i)&1;
            if(temp->links[bit]==NULL)
                temp->links[bit]=new Node();
            temp=temp->links[bit];
        }
    }

    // To find maximum XOR of given number with numbers stored in trie
    int maxXOR(int value)
    {
        Node *temp=root;
        
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(value>>i) & 1;
            if(temp->links[1-bit]!=NULL)
            {
                ans|=1<<i;
                temp=temp->links[1-bit];
            }
            else
                temp=temp->links[bit];
        }

        return(ans);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        
        // Storing binary representations of the number in the trie
        for(int i=0;i<nums.size();i++)
            t.insert(nums[i]);

        // Finding maximum XOR of two numbers
        int max_val=INT_MIN;
        for(int i=0;i<nums.size();i++)
            max_val=max(max_val,t.maxXOR(nums[i]));
        
        return(max_val);    // Return Maximum XOR
    }
};

// T.C=O(32*N)  ;   S.C=O(32*N)
// PATTERN - USING BINARY TRIE TO STORE SET OF BINARY NUMBERS 
