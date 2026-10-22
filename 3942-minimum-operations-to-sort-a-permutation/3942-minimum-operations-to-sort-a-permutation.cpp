class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int asc=0,dsc=0;
        for(int i=1;i<n;i++)
        {
            asc+=(nums[i]==(nums[i-1]+1)%n);
            dsc+=(nums[i-1]==(nums[i]+1)%n);
        }
        if(asc==(n-1) && nums[0]==0)
            return 0;
        if(asc==n-1)
        {
            int leftR = n-nums[0];
            int rightR = 1+(nums.back()+1)+1;
            return min(leftR,rightR);
        }
        if(dsc==n-1)
        {
            int leftR = 1 + n-nums.back();
            int rightR = ((nums[0]+1)%n)+1;
            return min(leftR,rightR);
        }
        return -1;
    }
};