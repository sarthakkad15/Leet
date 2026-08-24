class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<int> dr, vector<int> dc, int row, int col, vector<vector<bool>>& vis, int m, int n)
    {
        if(vis[row][col])
            return;
        vis[row][col]=true;
        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O')
                dfs(board,dr,dc,nr,nc,vis,m,n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
                dfs(board,dr,dc,0,i,vis,m,n);
            if(board[m-1][i]=='O')
                dfs(board,dr,dc,m-1,i,vis,m,n);
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                dfs(board,dr,dc,i,0,vis,m,n);
            if(board[i][n-1]=='O')
                dfs(board,dr,dc,i,n-1,vis,m,n);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};