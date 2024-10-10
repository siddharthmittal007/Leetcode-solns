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
    void preorderHelper(TreeNode *node,vector<int> &ans)
    {
        if(node!=nullptr)
        {
            ans.push_back(node->val);
            preorderHelper(node->left,ans);
            preorderHelper(node->right,ans);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>  ans;
        preorderHelper(root,ans);
        return(ans);
    }
};