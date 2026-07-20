class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(),j=0;
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0]});
        int intervalEnd=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>intervalEnd)
            {
               ans[j].push_back(intervalEnd);
               ans.push_back({intervals[i][0]});
               j++;
               intervalEnd=intervals[i][1];
            }
            else
            {
                intervalEnd=max(intervalEnd,intervals[i][1]);
            }
        }
        ans[j].push_back(intervalEnd);
        return ans;
    }
};