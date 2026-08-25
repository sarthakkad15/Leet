class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<int> dr, vector<int> dc, int row, int col, vector<vector<bool>>& vis, int m, int n)
    {
        if(vis[row][col])
            return;
        vis[row][col]=true;
        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1)
                dfs(grid,dr,dc,nr,nc,vis,m,n);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1)
                dfs(grid,dr,dc,0,i,vis,m,n);
            if(grid[m-1][i]==1)
                dfs(grid,dr,dc,m-1,i,vis,m,n);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
                dfs(grid,dr,dc,i,0,vis,m,n);
            if(grid[i][n-1]==1)
                dfs(grid,dr,dc,i,n-1,vis,m,n);
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                    count++;
            }
        }
        return count;
    }
};