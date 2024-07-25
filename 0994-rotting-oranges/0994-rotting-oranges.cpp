class Solution {
public:    
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;              // Minimum number of minutes

        vector<pair<int,int>> directions=
                        {{0,1},{0,-1},{1,0},{-1,0}};    // 'N' 'S' 'E' 'W'
        
        queue<pair<int,int>> q;     // Queue to implement bfs
        
        // Pushing rotten oranges to queue
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        q.push({-1,-1});            // To keep track of minutes

        // Breadth First Propogation
        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();
            
            if(i==-1 && j==-1)
            {
                if(!q.empty())
                {
                    // Increment minutes
                    minutes++;
                    q.push({-1,-1});
                }   
                continue;
            }
            
            // Visiting 4-Directional neighbours of current cell
            for(int cnt=0;cnt<4;cnt++)
            {
                int r=i+directions[cnt].first,c=j+directions[cnt].second;
                if  ((0<=r && r<grid.size()) && (0<=c && c<grid[0].size())
                    && grid[r][c]==1)
                {
                    grid[r][c]=0;
                    q.push({r,c});
                }
            }
        }

        // Checking if any fresh orange left
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

        return(minutes);    // Minimum number of minutes for all oranges 
                            // to get rotten
    }
};

// T.C=O(M*N)   ;`S.C=O(M*N)

// put all rootten oranges in calling funtion itself and dont create extra fucntion
