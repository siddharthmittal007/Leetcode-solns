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
        long long s=0,e=0;
        int max_width=1;
        queue<pair<TreeNode*,long long>> q;       // Queue of (Node,column)
        q.push({root,0});                   // Push root
        q.push({nullptr,NULL});             // Sentinel to mark EOL
        while(!q.empty())
        {
            TreeNode *curr=q.front().first;
            long long col=q.front().second;
            q.pop();

            if(curr==nullptr)
            {
                if(!q.empty())
                {
                    s=q.front().second,e=q.back().second;
                    int width=int(e-s+1);
                    if(width>max_width)max_width=width;
                    q.push({nullptr,NULL});     // Sentinel to mark EOL
                }
            }
            else
            {
                if(curr->left!=nullptr)q.push({curr->left,2*(col-s)});
                if(curr->right!=nullptr)q.push({curr->right,2*(col-s)+1});
            }
        }

        return(max_width);
    }
};