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
    int f(TreeNode *curr,bool &ans)
    {
        // Stopping either if null node or tree already found unbalanced
        if(curr==nullptr || ans==false)return(0);
        
        // Checking if unbalanced
        int d1=f(curr->left,ans), d2=f(curr->right,ans);
        if(abs(d1-d2)>1)ans=false;
        return(max(d1,d2)+1);
    }

    bool isBalanced(TreeNode* root) {
        bool ans=true;
        f(root,ans);
        return(ans);
    }
};