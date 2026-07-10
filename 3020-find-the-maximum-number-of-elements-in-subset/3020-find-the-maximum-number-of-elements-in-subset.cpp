class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size(),count,ans=1;
        long long x;
        map<long long,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            count=1;
            x=nums[i];
            if(x==1)
            {
                if(m[x]%2==0)
                    count=m[x]-1;
                else
                    count=m[x];
                ans=max(count,ans);
                continue;
            }
            while(m[x]>1)
            {
                if(m[pow(x,2)]>0)
                {
                    x=pow(x,2);
                    count+=2;
                }
                else
                    break;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};