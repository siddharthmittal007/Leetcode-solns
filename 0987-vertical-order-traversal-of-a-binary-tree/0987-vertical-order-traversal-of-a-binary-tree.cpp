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
    static bool comp(pair<int,int> &A, pair<int,int> &B)
    {
        if(A.first==B.first)
            return(A.second<B.second);
        else
            return(A.first<B.first);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;        // To store vertical order traversal

        // Level order traversal
        queue<pair<TreeNode*,pair<int,int>>> q;     // Queue (Node,(row,col))
        map<int,vector<pair<int,int>>> m;           // (Col, array of(row,val))
        if(root!=nullptr)
        {
            q.push({root,{0,0}});
            m[0].push_back({0,root->val});
        }

        while(!q.empty())
        {
            TreeNode *curr=q.front().first;
            int r=q.front().second.first, c=q.front().second.second;
            q.pop();

            if(curr->left!=nullptr)
            {
                q.push({curr->left,{r+1,c-1}});
                m[c-1].push_back({r+1,curr->left->val});
            }

            if(curr->right!=nullptr)
            {
                q.push({curr->right,{r+1,c+1}});
                m[c+1].push_back({r+1,curr->right->val});
            }
        }

        for(auto it=m.begin();it!=m.end();it++)
        {
            vector<int> v;
            sort(it->second.begin(),it->second.end(),comp);
            for(int i=0;i<it->second.size();i++)
                v.push_back(it->second[i].second);
            ans.push_back(v);
        }

        return(ans);
    }
};