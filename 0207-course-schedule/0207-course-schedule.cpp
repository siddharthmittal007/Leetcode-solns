class Solution {
public:
    void dfs(int u,vector<vector<int>> &adj,vector<int> &color,bool &cycle){
        color[u]=1;
        for(int v : adj[u]){
            //  Early stop to DFS
            if(cycle)return;
            // DFS
            if(color[v]==0)dfs(v,adj,color,cycle);
            else if(color[v]==1)cycle=true;
        }
        color[u]=2;
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        // Forming graph
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
            adj[edges[i][1]].push_back(edges[i][0]);

        // Checking cycle DFS
        vector<int> color(n,0);
        bool cycle=false;
        for(int i=0;i<n;i++){
            if(cycle)break;
            if(color[i]==0)dfs(i,adj,color,cycle);
        }
        return(!cycle);
    }
};