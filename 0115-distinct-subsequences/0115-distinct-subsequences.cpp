class Solution {
public:
    int solve(string s, string t, vector<vector<int>>& dp, int i, int j)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=solve(s,t,dp,i-1,j-1)+solve(s,t,dp,i-1,j);
        else
            return dp[i][j]=solve(s,t,dp,i-1,j);
    }
    int numDistinct(string s, string t) {
        int s_len=s.length();
        int t_len=t.length();
        vector<vector<int>> dp(s_len,vector<int>(t_len,-1));
        return solve(s,t,dp,s_len-1,t_len-1);
    }
};