class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,c=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                maxi=max(maxi,++c);
            else if(s[i]==')')
                c--;
        }
        return maxi;
    }
};