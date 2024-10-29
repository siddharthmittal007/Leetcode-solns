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
    int solve(TreeNode *curr,int &ans)
    {
        // Null Node
        if(curr==nullptr)return(0);
        
        // Maximum Straight Path Sums to children in left and right subtree
        int l=solve(curr->left,ans), r=solve(curr->right,ans);
        
        // Maximum path sum for path with highest node 'curr' 
        int maxPathSum=curr->val+l+r;
        if(maxPathSum>ans)ans=maxPathSum;
        
        // Return max straight path sum
        int straightPathSum=curr->val+max(l,r);
        return(straightPathSum>0?straightPathSum:0);
    }
    
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return(ans);
    }
};