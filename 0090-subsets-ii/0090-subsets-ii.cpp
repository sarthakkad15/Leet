class Solution {
public:
    void generate(int idx,vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int n)
    {
        if(curr.size()>n)
            return;
        ans.push_back(curr);
        for(int i=idx;i<n;i++)
        {
            if(i>idx && nums[i-1]==nums[i])
                continue;
            curr.push_back(nums[i]);
            generate(i+1,nums,ans,curr,n);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        generate(0,nums,ans,curr,n);
        return ans;
    }
};