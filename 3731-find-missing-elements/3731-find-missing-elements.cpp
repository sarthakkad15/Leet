class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size(),pt=0;
        sort(nums.begin(),nums.end());
        vector<int> missing;
        for(int i=nums[0];i<nums[n-1];i++)
        {
            if(i!=nums[pt])
                missing.push_back(i);
            else
                pt++;
        }
        return missing;
    }
};