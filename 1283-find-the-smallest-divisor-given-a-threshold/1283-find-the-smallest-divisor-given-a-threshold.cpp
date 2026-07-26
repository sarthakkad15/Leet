class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1,end = *max_element(nums.begin(), nums.end()),mid,ans,sum,n=nums.size();
        while(start<=end)
        {
            mid=start+(end-start)/2;
            sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=ceil((double)nums[i]/mid);
            }
            if(sum>threshold)
                start=mid+1;
            else
            {
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};