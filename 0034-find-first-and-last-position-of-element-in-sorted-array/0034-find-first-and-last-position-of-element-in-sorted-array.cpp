class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int mid,start=0,end=n-1,ind=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(target>nums[mid])
                start=mid+1;
            else if(target<nums[mid])
                end=mid-1;
            else
            {
                ind=mid;
                break;
            }
        }
        if(ind==-1)
            return {-1,-1};
        int fo=ind,lo=ind;
        while(fo>0 && nums[fo-1]==nums[fo])
            fo--;
        while(lo<n-1 && nums[lo+1]==nums[lo])
            lo++;
        return {fo,lo};
    }
};