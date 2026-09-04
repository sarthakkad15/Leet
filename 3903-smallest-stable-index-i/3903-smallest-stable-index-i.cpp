class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=(nums[i]>pre[i-1])?nums[i]:pre[i-1];
            suff[n-i-1]=(nums[n-i-1]>suff[n-i])?suff[n-i]:nums[n-i-1];
        }
        for(int i=0;i<n;i++)
        {
            if((pre[i]-suff[i])<=k)
                return i;
        }
        return -1;
    }
};