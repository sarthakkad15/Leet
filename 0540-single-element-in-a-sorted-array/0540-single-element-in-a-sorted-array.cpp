class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1,mid;
        if(n==1)
            return nums[start];
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(mid==0 && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(mid==n-1 && nums[mid]!=nums[mid-1])
                return nums[mid];
            else if(nums[mid]==nums[mid-1])
            {
                if(mid%2!=0)
                    start=mid+1;
                else
                    end=mid-1;
            }
            else if(nums[mid]==nums[mid+1])
            {
                if(mid%2==0)
                    start=mid+1;
                else
                    end=mid-1;
            }
            else
                return nums[mid];
        }
        return -1;
    }
};