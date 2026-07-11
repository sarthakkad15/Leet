class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(),ans;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto i:m)
        {
            if(i.second==1)
            {
                ans=i.first;
                break;
            }
        }
        return ans;
    }
};