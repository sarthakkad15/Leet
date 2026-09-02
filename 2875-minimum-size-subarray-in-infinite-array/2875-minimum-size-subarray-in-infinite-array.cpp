class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int i=0,j=0,sum=0,n=nums.size(),len=0,ans=INT_MAX;
        while(i<n)
        {
            while(sum<target)
            {
                sum+=nums[j];
                j++;
                len++;
                if(j==n)
                    j=0;
            }
            if(sum==target)
                ans=min(ans,len);
            sum-=nums[i];
            i++;
            len--;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};