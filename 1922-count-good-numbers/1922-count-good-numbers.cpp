class Solution {
public:
    int mod = 1e9+7;
    int power(int x, long long n)
    {
        if(n==0)
            return 1;
        long long half = power(x,n/2);
        if(n%2==0)
            return (half*half)%mod;
        return (1LL*x*half*half)%mod;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        return (1LL*power(5,even)*power(4,odd))%mod;
    }
};