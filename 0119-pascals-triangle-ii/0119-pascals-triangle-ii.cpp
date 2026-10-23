class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        dp.push_back({1});
        dp.push_back({1,1});
        if(rowIndex<2)
            return dp[rowIndex];
        for(int i=2;i<=rowIndex;i++)
        {
            vector<int> curr(i+1);
            dp.push_back(curr);
            dp[i][0] = dp[i][i] = 1;
            for(int j=1;j<i;j++)
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[rowIndex];
    }
};