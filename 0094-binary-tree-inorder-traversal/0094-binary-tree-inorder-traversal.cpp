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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;        // To save inorder traversal
        stack<TreeNode*> s;     // Stack of tree node pointers

        // Finding inorder traversal
        TreeNode *temp=root;
        while(temp!=nullptr || !s.empty())
        {
            while(temp!=nullptr)
            {
                s.push(temp);
                temp=temp->left;
            }
            ans.push_back(s.top()->val);
            temp=s.top()->right;
            s.pop();
        }
        
        return(ans);
    }
};