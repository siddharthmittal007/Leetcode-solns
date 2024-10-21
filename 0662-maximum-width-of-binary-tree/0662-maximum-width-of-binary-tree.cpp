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
    int widthOfBinaryTree(TreeNode* root) {
        // Empty Tree
        if(root==nullptr)
            return(0);

        // level order traversal
        int max_width=0;
        queue<pair<TreeNode*,int>> q;       // Queue of (Node,column)
        q.push({root,0});
        q.push({nullptr,NULL});             // Sentinel to mark EOL
        while(!q.empty())
        {
            TreeNode *curr=q.front().first;
            int col=q.front().second;
            q.pop();

            if(curr==nullptr)
            {
                if(!q.empty())
                {
                    int s=q.front().second, e=q.back().second;
                    int width=e-s+1;
                    if(width>max_width)max_width=width;
                    q.push({nullptr,NULL});     // Sentinel to mark EOL
                }
            }
            else
            {
                if(curr->left!=nullptr)q.push({curr->left,2*col});
                if(curr->right!=nullptr)q.push({curr->right,2*col+1});
            }
        }

        return(max_width);
    }
};