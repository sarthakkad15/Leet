class Solution {
public:
    long long dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int m, int n, int row, int col, const vector<int>& dr, const vector<int>& dc)
    {
        vis[row][col]=true;
        long long sum=grid[row][col];
        for(int i=0;i<4;i++)
        {
            int r1=row+dr[i];
            int c1=col+dc[i];
            if(r1<0 || c1<0 || r1>=m || c1>=n)
                continue;
            if(!vis[r1][c1] && grid[r1][c1]!=0)
                sum+=dfs(grid,vis,m,n,r1,c1,dr,dc);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size(),ans=0;
        long long sum;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,-1,0,1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0 && !vis[i][j])
                {
                    sum=dfs(grid,vis,m,n,i,j,dr,dc);
                    if(sum%k==0)
                        ans++;
                }
            }
        }
        return ans;
    }
};