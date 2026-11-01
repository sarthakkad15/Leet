class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x = *min_element(nums.begin(),nums.end()),ans=0;
        for(int i:nums)
        {
            ans+=i-x;
        }
        return ans;
    }
};