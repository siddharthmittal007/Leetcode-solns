class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<pair<int,int>> &directions,int i,int j)
    {
        int minutes=0;              // Minutes taken
        
        queue<pair<int,int>> q;     // Queue to implement bfs
        
        // Pushing starting point to queue
        grid[i][j]=0;
        q.push({i,j});
        
        q.push({-1,-1});    // For minute++

        // bfs
        while(!q.empty())
        {
            int r=q.front().first,c=q.front().second;
            q.pop();
            
            // minute++
            if(r==-1 && c==-1)
            {
                if(q.empty())
                {
                    break;
                }   
                minutes++;
                q.push({-1,-1});
                continue;
            }
            
            // Visiting 4-Directional neighbours of current cell
            for(int cnt=0;cnt<4;cnt++)
            {
                int _r=r+directions[cnt].first,_c=c+directions[cnt].second;
                if  ((0<=_r && _r<grid.size()) && (0<=_c && _c<grid[0].size())
                    && grid[_r][_c]==1)
                {
                    grid[_r][_c]=0;
                    q.push({_r,_c});
                }
            }
        }

        return(minutes);
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;      // Minimum number of minutes

        vector<pair<int,int>> directions=
                        {{0,1},{0,-1},{1,0},{-1,0}};    // 'N' 'S' 'E' 'W'
        
        // Calling bfs
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    minutes=max(minutes,bfs(grid,directions,i,j));
                }
            }
        }

        // Checking if fresh orange left
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return(-1);
                }
            }
        }

        return(minutes);
    }
};