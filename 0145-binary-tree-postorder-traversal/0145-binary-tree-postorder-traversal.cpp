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

        // Finding postorder traversal
        TreeNode *previousNode=nullptr;
        TreeNode *curr=root;
        
        while(curr!=nullptr || !s.empty())
        {
            if(curr!=nullptr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode *temp=s.top();
                if(temp->right==nullptr || temp->right==previousNode)
                {
                    ans.push_back(temp->val);
                    s.pop();
                    previousNode=temp;
                }
                else
                    curr=temp->right;                
            }
        }

        return(ans);
    }
};

// T.C=O(N)   ;   S.C=O(N)
// PATTERN - TREE TRAVERSAL