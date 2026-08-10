class Solution {
public:
    void checksum(int currSum, int target, vector<int>& candidates,vector<int>& curr, vector<vector<int>>& ans,int n,int idx)    {
        if(currSum>target)
            return;
        else if(currSum==target)
        {
            ans.push_back(curr);
            return;
        }
        else
        {
            for(int i=idx;i<n;i++)
            {
                if(i > idx && candidates[i] == candidates[i-1])
                    continue;
                curr.push_back(candidates[i]);
                checksum(currSum+candidates[i],target,candidates,curr,ans,n,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        checksum(0,target,candidates,curr,ans,n,0);
        return ans;
    }
};