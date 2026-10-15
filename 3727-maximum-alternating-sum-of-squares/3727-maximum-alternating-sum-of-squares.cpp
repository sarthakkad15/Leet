class Solution {
public:
    static bool compare(const int a, const int b)
    {
        return abs(a)<abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        int n=nums.size(),a=0,b=n-1;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                sum+=nums[b]*nums[b];
                b--;
            }
            else
            {
                sum-=nums[a]*nums[a];
                a++;
            }
        }
        return sum;
    }
};