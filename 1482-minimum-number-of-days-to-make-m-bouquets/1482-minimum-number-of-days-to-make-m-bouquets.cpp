class Solution {
public:
    bool check(vector<int>& bloomDay, int days, int m, int k, int n)
    {
        int k1=k;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=days)
                k--;
            else
                k=k1;
            if(k==0)
            {
                k=k1;
                m--;
            }
            if(m==0)
                return true;

        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size(),maxi=INT_MIN;
        if(1LL*m*k>n)
            return -1;
        for(int i=0;i<n;i++)
        {
            if(maxi<bloomDay[i])
                maxi=bloomDay[i];
        }
        int start=1,end=maxi,mid,ans;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(check(bloomDay,mid,m,k,n))
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};