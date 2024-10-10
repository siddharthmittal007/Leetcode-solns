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
    // Recursive Function
    void inorderHelper(TreeNode *node,vector<int> &ans)
    {
        if(node!=nullptr)
        {
            inorderHelper(node->left,ans);
            ans.push_back(node->val);
            inorderHelper(node->right,ans);
        }    
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderHelper(root,ans);
        return(ans);
    }
};

// T.C=O(N) ;   S.C=O(N)
// PATTERN - TREE TRAVERSAL