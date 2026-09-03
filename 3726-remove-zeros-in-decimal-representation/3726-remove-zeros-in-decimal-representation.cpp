class Solution {
public:
    long long removeZeros(long long n) {
        long long ans=0;
        while(n!=0)
        {
            int r=n%10;
            if(r!=0)
                ans=ans*10+r;
            n/=10;
        }
        n=ans;
        ans=0;
        while(n!=0)
        {
            int r=n%10;
            ans=ans*10+r;
            n/=10;
        }
        return ans;
    }
};