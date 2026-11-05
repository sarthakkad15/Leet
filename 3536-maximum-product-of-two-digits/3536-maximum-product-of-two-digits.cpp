class Solution {
public:
    int maxProduct(int n) {
        int r,mx=-1,mx2=-1;
        while(n>0)
        {
            r=n%10;
            if(mx==-1)
                mx=r;
            else if(r>=mx)
            {
                mx2=mx;
                mx=r;
            }
            else if(r>mx2)
                mx2=r;
            n/=10;
        }
        return mx*mx2;
    }
};