class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set <int> row,column;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(int i:row)
        {
            fill(matrix[i].begin(),matrix[i].end(),0);
        }
        for(int i:column)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][i]=0;
            }
        }
    }
};