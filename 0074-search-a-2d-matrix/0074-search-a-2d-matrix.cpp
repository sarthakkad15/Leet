class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int start=0,end=m-1,mid,row;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(matrix[mid][0]>target)
                end=mid-1;
            else if(matrix[mid][0]<target)
            {
                row=mid;
                start=mid+1;
            }
            else
                return true;
        }
        start=0,end=n-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(matrix[row][mid]>target)
                end=mid-1;
            else if(matrix[row][mid]<target)
                start=mid+1;
            else
                return true;
        }
        return false;
    }
};