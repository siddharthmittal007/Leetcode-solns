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
        vector<int>  ans;                   // To hold postorder traversal
        stack<pair<TreeNode*,bool>> s;      // Stack of node (pointer,flag) to
                                            // indicate expansion status

        // Finding postorder traversal
        s.push({root,true});
        while(!s.empty())
        {
            auto curr=s.top();
            s.pop();
            if(curr.first!=nullptr)
            {
                if(curr.second==true)
                {
                    s.push({curr.first,false});
                    s.push({curr.first->right,true});
                    s.push({curr.first->left,true});
                }
                else
                    ans.push_back(curr.first->val);
            }
        }
 
        return(ans);
    }
};