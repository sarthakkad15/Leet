class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.length(),ans=0;
        if(n==0 || n==1)
            return n;
        vector<int> map(256,0);
        map[s[0]]=1;
        while(j<n)
        {
            while(j<n-1 && map[s[j+1]]==0)
            {
                j++;
                map[s[j]]++;
            }
            ans=max(ans,j-i+1);
            if(j==n-1)
               break;
            map[s[i]]--;
            i++;
        }
        return ans;
    }
};