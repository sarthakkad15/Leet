class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c >= 'a' && c <= 'z')
                ans+=c;
            else if(c=='*' && !ans.empty())
                ans.pop_back();
            else if(c=='#' && !ans.empty())
                ans+=ans;
            else if(c=='%' && !ans.empty())
                reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};