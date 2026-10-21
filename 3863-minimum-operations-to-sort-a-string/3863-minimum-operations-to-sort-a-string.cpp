class Solution {
public:
    int minOperations(string s) {
        string s2=s;
        sort(s2.begin(),s2.end());
        if(s==s2)
            return 0;
        int n=s.length();
        if(n==2)
            return -1;
        if(s2[0]==s[0] || s2[n-1]==s[n-1])
            return 1;
        else if((s[0]==s2[n-1] && s2[n-1]!=s2[n-2]) && (s[n-1]==s2[0] && s2[0]!=s2[1]))
            return 3;
        else
            return 2;
    }
};