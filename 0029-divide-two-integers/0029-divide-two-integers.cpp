class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)
            return 1;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(divisor==1)
            return dividend;
        bool pos=true;
        if(dividend>0 && divisor<0)
            pos=false;
        if(dividend<0 && divisor>0)
            pos=false;
        long n=abs((long)dividend);
        long d=abs((long)divisor);
        int count=0;
        long ans=0;
        while(n>=d)
        {
            count=0;
            while(n>=(d<<(count+1)))
                count++;
            ans+=1<<count;
            n-=d<<(count);
        }
        return pos?ans:-ans;
    }
};