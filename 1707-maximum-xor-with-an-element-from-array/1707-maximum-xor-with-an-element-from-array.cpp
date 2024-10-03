class Node{
public:
    Node *links[2];
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

    // Add number in binary to trie
    void addNumber(int k)
    {
        Node *temp=root;
        for(int i=30;i>=0;i--)
        {
            int bit=(k>>i)&1;
            if(temp->links[bit]==NULL)
                temp->links[bit]=new Node();
            temp=temp->links[bit];
        }
    }

    // Max XOR of 'x' with an element 'y' in trie s.t y<=m  
    int maxXOR(int x,int m)
    {
        Node *ptr=root;     // Trie crawler
        int y=0;            // Trie member
        int ans=0;          // Max XOR
        Node  *temp=NULL;   // Root-to-node string is trie member
                            // producing next smaller max XOR val<m
        int bit_pos=-1;     // Bit position of 'temp' node

        for(int i=30;i>=0;i--)
        {
            int xbit=(x>>i)&1;
            int ybit=ptr->links[1-xbit]?1-xbit:xbit;
            
            int z=y|(ybit<<i);
            if(z<=m)
            {
                if(ybit==1 && ptr->links[0])
                {
                    temp=ptr->links[0];
                    bit_pos=i+1;
                }
                y|=ybit<<i;
                ans|=(xbit^ybit)<<i;
                ptr=ptr->links[ybit];
            }
            else if(ptr->links[0])
            {
                ptr=ptr->links[0];
            }
            else if(temp!=NULL)
            {
                ptr=temp;
                y&=(1<<30)-(1<<bit_pos)+(1<<30);
                ans&=(1<<30)-(1<<bit_pos)+(1<<30);
                i=bit_pos-1;
            } 
            else
            {
                ans=-1;
                break;
            }
        }

        return(ans);
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        
        for(int i=0;i<nums.size();i++)
            t.addNumber(nums[i]);
        
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++)
            ans[i]=t.maxXOR(queries[i][0],queries[i][1]);
        
        return(ans);
    }
};