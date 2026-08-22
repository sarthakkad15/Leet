class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc])
            return image;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        vector<int> dr={0,1,0,-1};
        vector<int> dc={-1,0,1,0,};
        q.push({sr,sc});
        int orig=image[sr][sc];
        while(!q.empty())
        {
            auto loc=q.front();
            q.pop();
            image[loc.first][loc.second]=color;
            for(int i=0;i<4;i++)
            {
                int row=loc.first+dr[i];
                int col=loc.second+dc[i];
                if(row>=0 && col>=0 && row<m && col<n && image[row][col]==orig)
                    q.push({row,col});
            }
        }
        return image;
    }
};