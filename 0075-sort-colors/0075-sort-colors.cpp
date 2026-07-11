class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),low=0,mid=0;
        int high=n-1;
        //Dutch National Flag Algo
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
            else if(nums[mid]==1)
                mid++;
        }
    }
};