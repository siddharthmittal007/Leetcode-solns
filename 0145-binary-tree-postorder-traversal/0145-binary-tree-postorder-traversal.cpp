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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>  ans;           // To hold postorder traversal
        stack<TreeNode*> s;         // Stack 

        // Finding reverse postorder traversal by dfs
        s.push(root);
        while(!s.empty())
        {
            TreeNode *temp=s.top();
            s.pop();
            if(temp!=nullptr)
            {
                ans.push_back(temp->val);
                s.push(temp->left);
                s.push(temp->right);
            }
        }
        
        // Obtaining postorder 
        reverse(ans.begin(),ans.end());
        
        return(ans);
    }
};