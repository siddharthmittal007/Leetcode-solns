/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode *curr,TreeNode *&lca,TreeNode *p,TreeNode *q)
    {
        // Returning if node is null or 'lca' already found
        if(curr==nullptr || lca!=nullptr)return(nullptr);

        // Checking if 'curr' is 'lca'
        TreeNode *l=solve(curr->left,lca,p,q), *r=solve(curr->right,lca,p,q);
        if(((curr==p || curr==q) && (l!=nullptr || r!=nullptr))
            || (l!=nullptr && r!=nullptr))
            lca=curr;
        
        if(curr==p || curr==q)return(curr);
        else return(l!=nullptr?l:r);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca=nullptr;
        solve(root,lca,p,q);
        return(lca);
    }
};