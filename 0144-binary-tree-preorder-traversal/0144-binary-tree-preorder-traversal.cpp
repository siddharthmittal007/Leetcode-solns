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
    // Utility function
    TreeNode* inorderPredecessor(TreeNode *curr)
    {
        TreeNode *temp=curr->left;
        while(temp->right!=nullptr && temp->right!=curr)
            temp=temp->right;
        return(temp);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>  ans;       // To store preorder traversal

        // Morris Preorder Traversal
        TreeNode *curr=root;
        while(curr!=nullptr)
        {
            if(curr->left!=nullptr)
            {
                TreeNode *temp=inorderPredecessor(curr);
                if(temp->right==nullptr)
                {
                    ans.push_back(curr->val);
                    temp->right=curr;       // Create thread
                    curr=curr->left;
                }
                else    // (temp->right==curr)
                {
                    temp->right=nullptr;    // Destroy thread
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

// T.C=O(3*N)   ;   S.C=O(1)
// PATTERN - TREE TRAVERSAL