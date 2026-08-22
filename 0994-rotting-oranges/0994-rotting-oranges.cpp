class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    count++;
            }
        }
        if(count==0)
            return 0;
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        int minutes=0; 
        while(!q.empty())
        {
            bool rotten=false;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto loc=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int row=loc.first+dr[j];
                    int col=loc.second+dc[j];
                    if(row>=0 && col>=0 && row<m && col<n && grid[row][col]==1)
                    {
                        q.push({row,col});
                        grid[row][col]=2;
                        count--;
                        rotten=true;
                    }
                }
            }
            if(rotten)
                minutes++;
        }
        if(count==0)
            return minutes;
        else
            return -1;
    }
};