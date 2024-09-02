class Node{
public:    
    Node* digit[2];

    Node(){
        digit[0]=digit[1]=NULL;
    }
};

class BinaryTree{
public:    
    Node *root;

    BinaryTree(){
        root=new Node();
    }

    void insert(int value)
    {
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int b=(value>>i)&1;
            if(temp->digit[b]==NULL)
                temp->digit[b]=new Node();
            temp=temp->digit[b];
        }
    }

    int max_XOR(int value)
    {
        int ans=0;
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
            ans=ans<<1;
            int b=(value>>i)&1;
            if(temp->digit[1-b]!=NULL)
            {
                ans+=1;
                temp=temp->digit[1-b];
            }
            else if(temp->digit[b]!=NULL)
                temp=temp->digit[b];
            else
                ans+=b;
        }

        return(ans);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        BinaryTree bt;
        
        for(int i=0;i<nums.size();i++)
            bt.insert(nums[i]);

        int max_val=INT_MIN;
        for(int i=0;i<nums.size();i++)
            max_val=max(max_val,bt.max_XOR(nums[i]));
        
        return(max_val);
    }
};