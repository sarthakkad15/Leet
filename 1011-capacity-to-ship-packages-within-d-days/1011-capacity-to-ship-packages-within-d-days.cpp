class Solution {
public:
    bool check(vector<int>& weights, int days, int cap)
    {
        int temp=cap,n=weights.size();
        for(int i=0;i<n;i++)
        {
            if(days==0)
                return false;
            if(weights[i]>temp)
            {
                temp=cap;
                i--;
                days--;
                continue;
            }
            temp=temp-weights[i];
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*max_element(weights.begin(),weights.end()),end=accumulate(weights.begin(),weights.end(),0),mid,ans;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(check(weights,days,mid))
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