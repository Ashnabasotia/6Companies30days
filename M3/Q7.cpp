int helper (int I, int J, vector<vector<bool>>& visited, vector<vector<int>>& grid)
    {
        int ans = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> Q;
        Q.push({I,J});
        visited[I][J] = true;
        int  op_r[] = {-1,-1,0,1,1,1,0,-1};
        int  op_c[] = {0,1,1,1,0,-1,-1,-1};
        while(!Q.empty())
        {
            pair<int,int> point = Q.front();
            int i = point.first;
            int j = point.second;
            Q.pop();
            for(int k=0; k<8; k++)
            {
                int r = i+op_r[k];
                int c = j+op_c[k];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c] && !visited[r][c])
                {
                    ans++;
                    visited[r][c] = true;
                    Q.push({r,c});
                }
            }
        }
        
        return ans;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] && !visited[i][j])
                {
                    ans = max(ans,helper(i,j,visited,grid));
                }
            }
        }
        
        return ans;
    }