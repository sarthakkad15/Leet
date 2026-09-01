class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,ans=0;
        while(i<n && j<n)
        {
            while(j<n && (nums[j]==1 || k>0))
            {
                if(nums[j]==0)
                    k--;
                j++;
            }
            ans=max(ans,j-i);
            if(nums[i]==0)
                k++;
            i++;
        }
        return ans;
    }
};