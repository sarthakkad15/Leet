class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0,product=1,div;
        int m=n,r;
        while(m!=0)
        {
            r=m%10;
            product*=r;
            sum+=r;
            m/=10;
        }
        div=sum+product;
        if(n%div==0)
            return true;
        return false;
    }
};