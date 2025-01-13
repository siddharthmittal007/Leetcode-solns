class Solution {
public:
    void bfs(int node,vector<vector<int>>& graph,vector<int> &d,vector<int> &p,vector<bool> &visited,bool &oddCycle){
        queue<int> q;
        q.push(node);
        visited[node]=true;
        
        while(!q.empty() && !oddCycle){
            int u=q.front(); q.pop();
            for(int v : graph[u]){
                if(oddCycle)return;
                if(v!=p[u]){
                    if(!visited[v]){
                        d[v]=d[u]+1, p[v]=u;
                        bfs(v,graph,d,p,visited,oddCycle);
                    }
                    else if((d[u]-d[v])%2==0)oddCycle=true;
                }
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph){
        const int n=graph.size();

        // Checking if odd cycle(BFS)
        vector<int> d(n),p(n);
        vector<bool> visited(n,false);
        bool oddCycle=false;
        for(int i=0;i<n;i++){
            if(oddCycle)break;
            if(!visited[i]){
                d[i]=0, p[i]=-1;
                bfs(i,graph,d,p,visited,oddCycle);
            }
        }
        return(!oddCycle);
    }
};