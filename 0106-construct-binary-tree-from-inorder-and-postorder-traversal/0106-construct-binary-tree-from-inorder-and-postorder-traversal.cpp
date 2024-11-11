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
    TreeNode* solve(int e,int i1,int i2,vector<int>& inorder, 
    vector<int>& postorder, unordered_map<int,int> &ump)
    {
        if(i1>i2)return(nullptr);
        
        int ind=ump[postorder[e]];
        TreeNode *curr=new TreeNode(postorder[e]);
        curr->left=solve(e-1-(i2-ind),i1,ind-1,inorder,postorder,ump);
        curr->right=solve(e-1,ind+1,i2,inorder,postorder,ump);
        return(curr);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int n=inorder.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
            ump.insert({inorder[i],i});
        TreeNode *ans=solve(n-1,0,n-1,inorder,postorder,ump);
        return(ans);
    }
};