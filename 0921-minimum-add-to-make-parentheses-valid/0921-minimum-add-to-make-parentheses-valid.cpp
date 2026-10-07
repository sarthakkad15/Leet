class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0,c=0,ans=0;
        for(char i:s)
        {
            if(i=='(')
                o++;
            else if(i==')')
                c++;
            if(c>o)
            {
                ans++;
                o=c;
            }
        }
        ans+=o-c;
        return ans;
    }
};