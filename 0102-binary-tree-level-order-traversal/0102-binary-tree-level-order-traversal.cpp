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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;        // To store level order traversal
        
        // Level order traversal
        queue<TreeNode*> q;
        if(root!=nullptr)
            q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left!=nullptr)q.push(curr->left);
                if(curr->right!=nullptr)q.push(curr->right);
            }
            ans.push_back(v);
        }
        
        return(ans);
    }
};