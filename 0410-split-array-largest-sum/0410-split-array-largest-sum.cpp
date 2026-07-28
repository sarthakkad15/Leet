class Solution {
public:
    bool check(vector<int>& nums, int k, int sum)
    {
        int temp=sum,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>temp)
            {
                temp=sum;
                k--;
            }
            if(k==0)
                return false;
            temp=temp-nums[i];
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(),nums.end()),end=accumulate(nums.begin(),nums.end(),0),mid,ans;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(check(nums,k,mid))
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