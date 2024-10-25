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
    TreeNode* solve(TreeNode *curr,TreeNode* &lca,TreeNode *p,TreeNode *q)
    {
        if(curr==nullptr || lca!=nullptr)return(nullptr);

        TreeNode *l=solve(curr->left,lca,p,q), *r=solve(curr->right,lca,p,q);
        if(curr==p || curr==q)
        {
            if(l!=nullptr || r!=nullptr)
                lca=curr;
            return(curr);
        }
        else if(l!=nullptr && r!=nullptr)
            lca=curr;

        return(l!=nullptr?l:r);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca=nullptr;
        solve(root,lca,p,q);
        return(lca);
    }
};