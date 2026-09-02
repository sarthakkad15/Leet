class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n, vector<int>& dr, vector<int>& dc, int row, int col, vector<vector<bool>>& vis)
    {
        vis[row][col]=true;
        for(int i=0;i<4;i++)
        {
            int r=row+dr[i];
            int c=col+dc[i];
            if(r<m && c<n && r>=0 && c>=0 && grid[r][c]=='1' && !vis[r][c])
                dfs(grid,m,n,dr,dc,r,c,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,-1,0,1};
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(grid,m,n,dr,dc,i,j,vis);
                    c++;
                }
            }
        }
        return c;
    }
};