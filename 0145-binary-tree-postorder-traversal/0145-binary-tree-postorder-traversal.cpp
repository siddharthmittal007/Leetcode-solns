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
    TreeNode* inorderSuccessor(TreeNode *curr)
    {
        TreeNode *temp=curr->right;
        while(temp->left!=nullptr && temp->left!=curr)
            temp=temp->left;
        return(temp);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>  ans;           // To hold postorder traversal
        
        // Morris traversal to get reverse postorder traversal
        TreeNode *curr=root;
        while(curr!=nullptr)
        {
            if(curr->right!=nullptr)
            {
                TreeNode *temp=inorderSuccessor(curr);
                if(temp->left==nullptr)
                {
                    ans.push_back(curr->val);
                    temp->left=curr;        // Create thread
                    curr=curr->right;
                }
                else    // (temp->left==curr)
                {
                    temp->left=nullptr;     // Destroy thread
                    curr=curr->left;
                }
            }
            else
            {
                ans.push_back(curr->val);
                curr=curr->left;
            }
        }

        // Obtaining postorder 
        reverse(ans.begin(),ans.end());
        
        return(ans);
    }
};