class Solution {
public:
    int smallestNumber(int n, int t) {
        int m,r,prod;
        while(1)
        {
            m=n;
            prod=1;
            while(m!=0)
            {
                r=m%10;
                prod*=r;
                if(prod%t==0)
                    return n;
                m/=10;
            }
            n++;
        }
    }
};