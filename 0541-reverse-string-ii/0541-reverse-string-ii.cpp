class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length(),i=0;
        while(i<n)
        {
            if((n-i)<k)
                reverse(s.begin()+i,s.end());
            else
                reverse(s.begin()+i,s.begin()+i+k);
            i+=2*k;
        }
        return s;
    }
};