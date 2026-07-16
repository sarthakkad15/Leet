class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=n-1,u=0,d=m-1;
        vector<int> v;
        for(int i=l;i<=r;i++)
        {
            v.push_back(matrix[u][i]);
        }
        while(1)
        {
            if(!(u<d))
                break;
            for(int i=++u;i<=d;i++)
            {
                v.push_back(matrix[i][r]);
            }
            if(!(l<r))
                break;
            for(int i=--r;i>=l;i--)
            {
                v.push_back(matrix[d][i]);
            }
            if(!(u<d))
                break;
            for(int i=--d;i>=u;i--)
            {
                v.push_back(matrix[i][l]);
            }
            if(!(l<r))
                break;
            for(int i=++l;i<=r;i++)
            {
                v.push_back(matrix[u][i]);
            }
        }
        return v;
    }
};