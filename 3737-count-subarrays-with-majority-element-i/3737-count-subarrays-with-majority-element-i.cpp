class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(),count=0;
        vector<int> dp(n+1);
        dp[0]=0;
        
        for(int i=0;i<n;i++)
        {
            dp[i+1]=dp[i]+(nums[i]==target);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(2*(dp[j+1]-dp[i])>(j-i+1))
                    count++;
            }
        }
        return count;
    }
};