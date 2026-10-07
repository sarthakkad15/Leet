    class Solution {
    public:
        vector<string> res;
        int check_min(string s)
        {
            int bal=0,ans=0;
            for(char c:s)
            {
                if(c=='(')
                    bal++;
                else if(c==')')
                    bal--;
                if(bal<0)
                {
                    bal=0;
                    ans++;
                }
            }
            return ans+bal;
        }
        void solve(string &s, int idx, int bal, int minr, int n, string &curr)
        {
            if(bal==-1 || minr<0)
                return;
            if(idx==n)
            {
                if(bal==0 && minr==0)
                    res.push_back(curr);
                return;
            }
            if (s[idx] == '(' || s[idx] == ')') 
            {
                solve(s, idx + 1, bal, minr-1, n, curr);
            }

            curr.push_back(s[idx]);

            if (s[idx] == '(')
                solve(s, idx + 1, bal + 1, minr, n, curr);
            else if (s[idx] == ')')
                solve(s, idx + 1, bal - 1, minr, n, curr);
            else
                solve(s, idx + 1, bal, minr, n, curr);
            curr.pop_back();
        }
        vector<string> removeInvalidParentheses(string s) 
        {
            string curr="";
            solve(s,0,0,check_min(s),s.length(),curr);
            sort(res.begin(),res.end());
            res.erase(unique(res.begin(),res.end()),res.end());
            return res;
        }
    };