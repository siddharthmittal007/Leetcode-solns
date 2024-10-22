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
    int f(TreeNode *curr,int &max_dia)
    {
        if(curr==nullptr)return(0);
        int d1=f(curr->left,max_dia), d2=f(curr->right,max_dia);
        if(d1+d2>max_dia)max_dia=d1+d2;
        return(max(d1,d2)+1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
    int max_dia=0;
    f(root,max_dia);
    return(max_dia);
    }
};