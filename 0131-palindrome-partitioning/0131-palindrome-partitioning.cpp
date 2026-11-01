class Solution {
public: 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(0,s,ans,curr);
        return ans;
    }
    void dfs(int i, string s, vector<vector<string>>& ans, vector<string>& curr)
    {
        if(i==s.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(isPalindrome(i,j,s))
            {
                curr.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,ans,curr);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(int start, int end, string s)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};