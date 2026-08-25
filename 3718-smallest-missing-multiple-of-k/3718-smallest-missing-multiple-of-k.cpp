class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            if(s.find(k*i)==s.end())
                return k*i;
        }
        return k*(n+1);
    }
};