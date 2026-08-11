class Solution {
public:
    void generate(int k, int n, vector<vector<int>>& ans, vector<int>& curr,int idx,int sum)
    {
        if(k==0 && sum==n)
        {
            ans.push_back(curr);
            return;
        }
        if(k==0 || sum>n)
            return;
        for(int i=idx;i<=9;i++)
        {
            curr.push_back(i);
            generate(k-1,n,ans,curr,i+1,sum+i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        generate(k,n,ans,curr,1,0);
        return ans;
    }
};