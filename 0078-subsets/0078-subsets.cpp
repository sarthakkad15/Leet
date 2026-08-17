class Solution {
public:
    void generate(int n, vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx)
    {
        ans.push_back(curr);
        if(curr.size()==n)
            return;
        for(int i=idx;i<n;i++)
        {
            curr.push_back(nums[i]);
            generate(n,nums,ans,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n=nums.size();
        generate(n,nums,ans,curr,0);
        return ans;
    }
};