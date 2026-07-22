class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),k=-1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                k=i+1;
                break;
            }
        }
        if(k!=-1)
        {
            reverse(nums.begin(),nums.begin()+k);
            reverse(nums.begin()+k,nums.end());
            reverse(nums.begin(),nums.end());
        }
        int start=0,end=n-1,mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]>target)
                end=mid-1;
            else if(nums[mid]<target)
                start=mid+1;
            else if(k==-1)
                return mid;
            else
                return (mid+k)%n;
        }
        return -1;
    }
};