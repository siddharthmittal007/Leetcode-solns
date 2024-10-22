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
    void solve(TreeNode *curr,int d,int &max_d)
    {
        if(curr!=nullptr)
        {
            if(d>max_d)max_d=d;
            solve(curr->left,d+1,max_d);
            solve(curr->right,d+1,max_d);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int max_depth=0;
        solve(root,1,max_depth);
        return(max_depth);
    }
};

// T.C=O(N) ;   S.C=O(N)