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
    TreeNode* inorderPredecessor(TreeNode *curr)
    {
        TreeNode *temp=curr->left;
        while(temp->right!=nullptr && temp->right!=curr)
            temp=temp->right;
        return(temp);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;        // To save inorder traversal
        
        // Morris inorder traversal
        TreeNode *curr=root;
        while(curr!=nullptr)
        {
            if(curr->left!=nullptr)
            {
                TreeNode *temp=inorderPredecessor(curr);
                if(temp->right==nullptr)
                {
                    temp->right=curr;       // Create thread
                    curr=curr->left;
                }    
                else    // (temp->right==curr)
                {
                    temp->right=nullptr;    // Destroy thread
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }

        return(ans);
    }
};