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

        if(root==nullptr)
            return(ans);
        // Finding inorder traversal
        TreeNode *temp=root;
        do
        {
            cout<<"Axyzlmmo ";
            while(temp!=nullptr)
            {
                cout<<"B ";
                s.push(temp);
                temp=temp->left;
            }

            cout<<"C ";
            temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            temp=temp->right;
        }while(temp!=nullptr || !s.empty());
        
        return(ans);
    }
};