class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int start=0,end=n-1,mid,maxi=INT_MIN,idx;
        while(start<=end)
        {
            maxi=INT_MIN;
            mid=start+(end-start)/2;
            for(int i=0;i<m;i++)
            {
                if(maxi<mat[i][mid])
                {
                    maxi=mat[i][mid];
                    idx=i;
                }
            }
            int leftVal = (mid > 0) ? mat[idx][mid - 1] : -1;
            int rightVal = (mid < n - 1) ? mat[idx][mid + 1] : -1;
            if(mat[idx][mid] > leftVal && mat[idx][mid] > rightVal)
            {
                return {idx, mid};
            }
            if(leftVal > mat[idx][mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return {-1,-1};
    }
};