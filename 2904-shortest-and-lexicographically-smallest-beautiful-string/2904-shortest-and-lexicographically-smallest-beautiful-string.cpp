class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        int i=0,j=0,c=0;
        string ans;
        while(s[i]!='1')
        {
            i++;
            if(i==n)
                return "";
        }
        while(j<n)
        {
            while(s[i] == '0')
                i++;
            while(j<n && c<k)
            {
                if(s[j]=='1')
                    c++;
                j++;
            }
            if(c==k)
            {
                string candidate = s.substr(i,j-i);
                if(ans.empty() || candidate.length()<ans.length() || (candidate.length() == ans.length() && candidate < ans))
                    ans = candidate;
                i++;
                c--;
            }
        }
        return ans;
    }
};