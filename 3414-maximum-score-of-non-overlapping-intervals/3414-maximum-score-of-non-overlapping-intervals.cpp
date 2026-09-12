class Solution {
public:
    int findNext(vector<vector<int>>& intervals, int end, int n)
    {
        int low=0,high=n-1;
        int result=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(intervals[mid][0]>end)
            {
                result=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return result;
    }

    pair<long long,vector<int>> solve(vector<vector<int>>& intervals, int i, int k, vector<int>& nextIdx,int n,vector<vector<pair<long long,vector<int>>>>& dp)
    {
        if(k==0 || i>=n)
            return {0,{}};
        if(dp[i][k].first!=-1)
            return dp[i][k];
        pair<long long,vector<int>> nottaken=solve(intervals, i+1, k, nextIdx,n,dp);
        pair<long long,vector<int>> temp=solve(intervals,nextIdx[i],k-1,nextIdx,n,dp);
        pair<long long,vector<int>> taken;
        taken.first=temp.first+intervals[i][2];
        taken.second=temp.second;
        taken.second.push_back(intervals[i][3]);
        sort(taken.second.begin(), taken.second.end());
        if(taken.first > nottaken.first)
            dp[i][k] = taken;
        else if(taken.first < nottaken.first)
            dp[i][k] = nottaken;
        else
            dp[i][k] = (taken.second < nottaken.second)?taken:nottaken;
        return dp[i][k];

    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        vector<int> nextIdx(n);
        for(int i=0;i<n;i++)
        {
            int end=intervals[i][1];
            nextIdx[i]=findNext(intervals,end,n);
        }
        vector<vector<pair<long long,vector<int>>>> dp(n+1,vector<pair<long long,vector<int>>>(4+1,{-1,{}}));
        return solve(intervals,0,4,nextIdx,n,dp).second;
    }
};