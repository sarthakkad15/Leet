class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int start=0,end=n-1,mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]>target)
                end=mid-1;
            else if(nums[mid]<target)
                start=mid+1;
            else
                return true;
        }
        return false;
    }
};