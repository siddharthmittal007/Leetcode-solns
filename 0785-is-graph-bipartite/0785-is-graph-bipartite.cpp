class Solution {
public:
    void dfs(int u,vector<vector<int>>& graph,vector<int> &d,vector<int> &p,vector<bool> &visited,bool &oddCycle){
        visited[u]=true;
        for(int v : graph[u]){
            if(oddCycle)return;
            if(v!=p[u]){
                if(!visited[v]){
                    d[v]=d[u]+1, p[v]=u;
                    dfs(v,graph,d,p,visited,oddCycle);
                }
                else if((d[v]-d[u])%2==0)oddCycle=true;
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph){
        const int n=graph.size();

        // Checking if odd cycle(DFS)
        vector<int> d(n),p(n);
        vector<bool> visited(n,false);
        bool oddCycle=false;
        for(int i=0;i<n;i++){
            if(oddCycle)break;
            if(!visited[i]){
                d[i]=0, p[i]=-1;
                dfs(i,graph,d,p,visited,oddCycle);
            }
        }
        return(!oddCycle);
    }
};