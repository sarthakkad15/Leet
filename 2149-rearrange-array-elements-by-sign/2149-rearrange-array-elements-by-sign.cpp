class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1,arr2;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        for(int i=0;i<n/2;i++)
        {
            nums[2*i]=arr1[i];
            nums[2*i+1]=arr2[i];
        }
        return nums;
    }
};