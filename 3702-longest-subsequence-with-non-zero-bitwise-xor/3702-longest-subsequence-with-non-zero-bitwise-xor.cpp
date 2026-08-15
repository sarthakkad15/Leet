class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            total=total^nums[i];
        }
        if(total!=0)
            return n;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                return n-1;
        }
        return 0;
    }
};