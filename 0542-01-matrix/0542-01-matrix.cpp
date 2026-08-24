class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> dr={0,1,0,-1};
        vector<int> dc={-1,0,1,0,};
        vector<vector<int>> result(m,vector<int>(n,0));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            result[row][col]=steps;
            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc])
                {
                    vis[nr][nc]=true;
                    q.push({{nr,nc},steps+1});
                }

            }
        }
        return result;
    }
};