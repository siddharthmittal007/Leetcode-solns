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
    int maxXOR(int k)
    {
        // Trie empty
        if(root->links[0]==NULL && root->links[1]==NULL)
            return(-1);
    
        Node *ptr=root;     
        int ans=0;     

        for(int i=30;i>=0;i--)
        {
            int bit=(k>>i)&1;
            if(ptr->links[1-bit])
            {
                ans|=1<<i;
                ptr=ptr->links[1-bit];
            }
            else
                ptr=ptr->links[bit];
        }

        return(ans);
    }
};

// Custom Comparator
bool comp(pair<pair<int,int>,int> &A,pair<pair<int,int>,int> &B)
{
    return(A.first.second<B.first.second);
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Sorting input numbers
        sort(nums.begin(),nums.end());
        
        // Saving queries offline sorted on 'm'
        vector<pair<pair<int,int>,int>> offlineQueries(queries.size());
        for(int i=0;i<queries.size();i++)
            offlineQueries[i]={{queries[i][0],queries[i][1]},i};
        sort(offlineQueries.begin(),offlineQueries.end(),comp);

        // Finding max XORs
        Trie t;
        vector<int> ans(queries.size());

        int i=0;
        for(int j=0;j<offlineQueries.size();j++)
        {
            int x=offlineQueries[j].first.first,m=offlineQueries[j].first.second;
            int index=offlineQueries[j].second;
            while(i<nums.size() && nums[i]<=m)
                t.addNumber(nums[i++]);
            ans[index]=t.maxXOR(x);
        }

        return(ans);
    }
};

// T.C=O(32*N + N*log(N) + 32*M + M*log(M)) ;   S.C=O(32*N+M)
// PATTERN - STORING SET OF BINARY NUMBERS IN BINARY TREE
