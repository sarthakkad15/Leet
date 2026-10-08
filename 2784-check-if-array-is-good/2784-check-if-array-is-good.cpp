class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size(),c=1;
        if(n<2)
            return false;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==n-1 && vis[n-1] && c==1)
            {
                c--;
                continue;
            }
            if(nums[i]>=n || vis[nums[i]])
                return false;
            vis[nums[i]]=true;
        }
        if(c==1)
            return false;
        return true;
    }
};