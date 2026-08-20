class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int l1,l2,n=nums.size();
        for(int i=2;i<n;i++)
        {
            l1=arr1.size()-1;
            l2=arr2.size()-1;
            if(arr1[l1]>arr2[l2])
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};