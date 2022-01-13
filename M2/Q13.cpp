int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited (m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        queue<int>time;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0;j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    time.push(0);
                }
            }
        }
        
        int ans = 0;
        
        while(!q.empty())
        {
            pair<int,int> rotten = q.front();
            q.pop();
            visited[rotten.first][rotten.second] = true;
            int tmp = time.front();
            ans = max(ans,tmp);
            time.pop();
            
            int i = rotten.first;
            int j = rotten.second;
            
            if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1)
            {
                grid[i-1][j] = 2;
                time.push(tmp+1);
                q.push({i-1,j});
            }
            
            if(j+1<n && !visited[i][j+1] && grid[i][j+1] == 1)
            {
                grid[i][j+1] = 2;
                time.push(tmp+1);
                q.push({i,j+1});
            }
            
            if(i+1 < m && !visited[i+1][j] && grid[i+1][j] == 1)
            {
                grid[i+1][j] = 2;
                time.push(tmp+1);
                q.push({i+1,j});
            }
            
            if(j-1 >=0 && !visited[i][j-1] && grid[i][j-1] == 1)
            {
                grid[i][j-1] = 2;
                time.push(tmp+1);
                q.push({i,j-1});
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
        
    }