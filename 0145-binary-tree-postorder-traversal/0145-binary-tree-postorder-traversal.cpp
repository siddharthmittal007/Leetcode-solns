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

    // Utility function
    void printReverseList(TreeNode *node,vector<int> &ans)
    {
        // Reversing chain of right connected nodes
        TreeNode *succ=node, *pre=nullptr;
        while(succ!=nullptr)
        {
            TreeNode *temp=succ->right;
            succ->right=pre;
            pre=succ;
            succ=temp;
        }

        // Printing in reverse order while restoring original order
        succ=pre;
        pre=nullptr;
        while(succ!=nullptr)
        {
            ans.push_back(succ->val);
            TreeNode *temp=succ->right;
            succ->right=pre;
            pre=succ;
            succ=temp;
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>  ans;           // To hold postorder traversal

        // Morris postorder traversal
        TreeNode *dummy=new TreeNode();
        dummy->left=root;

        TreeNode *curr=dummy;
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
                else    // (temp->left==curr)
                {
                    temp->right=nullptr;    // Destroy thread
                    // Print reverse list of right connected nodes 
                    // starting curr->left
                    printReverseList(curr->left,ans);
                    curr=curr->right;
                }
            }
            else
                curr=curr->right;
        }
        return(ans);
    }
};

// T.C=O(5*N)   ;   S.C=O(1)
// PATTERN - TREE TRAVERSAL