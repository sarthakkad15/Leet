class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int start=1,end=x,mid,ans;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(1LL*mid*mid>x)
                end=mid-1;
            else
            {
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
};