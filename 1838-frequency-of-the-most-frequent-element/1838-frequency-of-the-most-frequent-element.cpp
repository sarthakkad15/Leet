class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int right=0,left=0,n=nums.size(),ans=1;
        long long sum=0;
        for(;right<n;right++)
        {
            sum+=nums[right];
            if(1LL*nums[right]*(right-left+1)-sum>k)
            {
                sum-=nums[left];
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};