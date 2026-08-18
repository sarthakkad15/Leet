class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n)
            return *max_element(nums.begin(),nums.end());
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        if(k==1)
        {
            int maxi=-1;
            for(auto i:freq)
            {
                if(i.second==1)
                    maxi=max(maxi,i.first);
            }
            return maxi;
        }
        if(freq[nums[0]]==1 && freq[nums[n-1]]!=1)
            return nums[0];
        else if(freq[nums[n-1]]==1 && freq[nums[0]]!=1)
            return nums[n-1];
        else if(freq[nums[0]]==1 && freq[nums[n-1]]==1)
            return max(nums[0],nums[n-1]);
        else
            return -1;
    }
};