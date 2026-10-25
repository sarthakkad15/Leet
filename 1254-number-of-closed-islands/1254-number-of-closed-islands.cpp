class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col, const vector<int> dr, const vector<int> dc, int m, int n)
    {
        vis[row][col]=true;
        for(int i=0;i<4;i++)
        {
            int r1=row+dr[i];
            int c1=col+dc[i];
            if(r1<0 || r1>=m || c1<0 || c1>=n)
               continue;
            if(grid[r1][c1]==0 && !vis[r1][c1])
                dfs(grid,vis,r1,c1,dr,dc,m,n);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0 && !vis[i][0])
                dfs(grid,vis,i,0,dr,dc,m,n);
            if(grid[i][n-1]==0 && !vis[i][n-1])
                dfs(grid,vis,i,n-1,dr,dc,m,n);
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==0 && !vis[0][i])
                dfs(grid,vis,0,i,dr,dc,m,n);
            if(grid[m-1][i]==0 && !vis[m-1][i])
                dfs(grid,vis,m-1,i,dr,dc,m,n);
        }
        int c=0;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(grid[i][j]==0 && !vis[i][j])
                {
                    c++;
                    dfs(grid,vis,i,j,dr,dc,m,n);
                }
            }
        }
        return c;
    }
};