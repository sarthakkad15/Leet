class Solution {
public:
    string smallestPalindrome(string s) {
        string ans="";
        int n=s.length();
        char mid;
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[i+1])
            {
                mid=s[i];
                continue;
            }
            ans+=s[i];
            i++;
        }
        int j=ans.length()-1;
        if(n%2!=0)
            ans+=mid;
        for(;j>=0;j--)
        {
            ans+=ans[j];
        }
        return ans;
    }
};