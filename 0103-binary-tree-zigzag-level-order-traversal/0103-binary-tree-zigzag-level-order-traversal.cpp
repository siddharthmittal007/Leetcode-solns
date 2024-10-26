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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;    // To store zigzag traversal
        queue<TreeNode*> q;         // Queue for BFS
        int flag=0;                 // To denote reverse traversal of level
        
        // Zigzag Level Order Traversal
        if(root!=nullptr)q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=nullptr)q.push(curr->left);
                if(curr->right!=nullptr)q.push(curr->right);

                int ind=(flag==1?size-i-1:i);
                v[ind]=curr->val;
            }
            ans.push_back(v);
            flag=flag^1;
        }
        
        return(ans);
    }
};

// T.C=O(N) ;   S.C=O(N)
// PATTERN - LEVEL ORDER TRAVERSAL