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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;            // To hold right side view
        
        if(root==nullptr)
            return(ans);
            
        // Level order traversal
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);            // To mark end of level
        
        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();
            if(curr!=nullptr)
            {
                if(q.front()==nullptr)
                    ans.push_back(curr->val);
                if(curr->left!=nullptr)q.push(curr->left);
                if(curr->right!=nullptr)q.push(curr->right);
            }
            else if(!q.empty())
                q.push(nullptr);    // To mark end of level
        }
        
        return(ans);
    }
};

// T.C=O(N) ;   S.C=O(D)(D IS DIAMETER)(WORST CASE O(N))
// ADDITONAL POINTS - LEFT VIEW OBTAINED SIMILARLY