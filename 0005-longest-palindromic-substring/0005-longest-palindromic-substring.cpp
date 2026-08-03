class Solution {
public:
    pair<int,int> checkAroundCenter(string s, int left, int right)
    {
        int n=s.size();
        while(left>=0 && right<n && s[left]==s[right])
        {
            right++;
            left--;
        }
        return {left+1,right-1};
    }
    string longestPalindrome(string s) {
        int n=s.size(),end=0,start=0;
        if(n==0)
            return "";
        for(int i=0;i<n;i++)
        {
            auto odd = checkAroundCenter(s,i,i);
            auto even = checkAroundCenter(s,i,i+1);
            if(odd.second-odd.first>end-start)
            {
                start=odd.first;
                end=odd.second;
            }
            if(even.second-even.first>end-start)
            {
                start=even.first;
                end=even.second;
            }
        }
        return s.substr(start,end-start+1);
    }
};