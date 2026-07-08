class Solution {
public:
    bool isPalindrome(int x) {
        int m=x,n,r=0;
        if(x<0)
            return false;
        while(m!=0)
        {
            n=m%10;
            if(r>INT_MAX/10 || r<INT_MIN/10)
                return 0;
            r=10*r+n;
            m=m/10;
        }
        if(x==r)
            return true;
        else
            return false; 
        }
};