/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int s, int i1, int i2,vector<int>& preorder, 
    vector<int>& inorder, unordered_map<int,int> &ump)
    {
        if(i1>i2)return(nullptr);
        int ind=ump[preorder[s]];
        TreeNode *curr=new  TreeNode(preorder[s]);
        curr->left=solve(s+1,i1,ind-1,preorder,inorder,ump);
        curr->right=solve(s+1+(ind-i1),ind+1,i2,preorder,inorder,ump);
        return(curr);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> ump;
        for(int i=0;i<inorder.size();i++)
            ump.insert({inorder[i],i});
        
        TreeNode *ans=solve(0,0,inorder.size()-1,preorder,inorder,ump);
        return(ans);
    }
};

// T.C=O(N) ;   S.C=O(N)