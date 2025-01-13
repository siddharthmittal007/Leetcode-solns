class Solution {
public:
    void bfs(int i,int j,vector<vector<char>> &grid,vector<vector<bool>> &visited,int n,int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            i=q.front().first, j=q.front().second; q.pop();
            visited[i][j]=true;
            if(j<m-1 && grid[i][j+1]=='1' && !visited[i][j+1])q.push({i,j+1});
            if(j>0 && grid[i][j-1]=='1' && !visited[i][j-1])q.push({i,j-1});
            if(i<n-1 && grid[i+1][j]=='1' && !visited[i+1][j])q.push({i+1,j});
            if(i>0 && grid[i-1][j]=='1' && !visited[i-1][j])q.push({i-1,j});
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        
        // Finding number of connected components(any search BFS/DFS)
        int cnt=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(i,j,grid,visited,n,m);
                    cnt++;
                }
            }
        }
        
        // Number of islands
        return(cnt);
    }
};