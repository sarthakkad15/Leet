class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN,n=piles.size();
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,piles[i]);
        }
        int start=1,end=maxi,mid,ans;
        long long hours;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            hours=0;
            for(int i=0;i<n;i++)
            {
                hours+=(piles[i]/mid);
                if(piles[i]%mid!=0)
                    hours++;
            }
            if(hours>h)
                start=mid+1;
            else if(hours<=h)
            {
                end=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};