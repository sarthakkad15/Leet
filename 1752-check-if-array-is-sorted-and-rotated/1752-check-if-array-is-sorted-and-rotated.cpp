class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> nums1 = nums;
        int n=nums.size();
        sort(nums1.begin(),nums1.end());
        int x=nums1[0];
        int i=0;
        while(nums[i]!=x)
            i++;
        if(i==0 && nums[0]==nums[n-1])
        {
            i=n-1;
            while(i>0 && nums[i-1]==nums[i])
                i--;
        }
        for(int j=0;j<n;j++)
        {
            if(nums[i]!=nums1[j])
                return false;
            i=(++i)%n;
        }
        return true;
    }
};