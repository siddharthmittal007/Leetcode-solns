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
    void traverse(TreeNode *curr,vector<int> &ans,int level,int &max_level)
    {
        if(curr!=nullptr)
        {
            if(level>max_level)
            {
                max_level=level;
                ans.push_back(curr->val);
            }
            traverse(curr->right,ans,level+1,max_level);
            traverse(curr->left,ans,level+1,max_level);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int max_level=-1;
        traverse(root,ans,0,max_level);
        return(ans);
    }
};