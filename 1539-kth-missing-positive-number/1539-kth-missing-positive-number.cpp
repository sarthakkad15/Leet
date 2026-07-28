class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(),total_miss;
        vector<int> missing(n);
        total_miss=arr[0]-1;
        missing[0]=total_miss;
        for(int i=1;i<n;i++)
        {
            total_miss=total_miss+arr[i]-arr[i-1]-1;
            missing[i]=total_miss;
        }
        int start=0,end=n-1,mid,idx,x;
        if(k<=missing[0])
        {
            x=missing[0]-k+1;
            return arr[0]-x;
        }
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(missing[mid]>=k)
                end=mid-1;
            else
            {
                idx=mid;
                start=mid+1;
            }
        }
        x=k-missing[idx];
        return arr[idx]+x;
    }
};