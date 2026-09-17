class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<long long> s;
        s.insert(nums[0]+nums[1]);
        int n=nums.size();
        long long x;
        for(int i=2;i<n;i++)
        {
            x=nums[i]+nums[i-1];
            if(s.find(x)!=s.end())
                return true;
            s.insert(x);
        }
        return false;
    }
};