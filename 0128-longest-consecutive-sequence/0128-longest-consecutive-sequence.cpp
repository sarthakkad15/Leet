class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> val(nums.begin(),nums.end());
        int ans=0,length=0,next;
        for(int i:val)
        {
            if(val.count(i-1))
                continue;
            length=1;
            next=i+1;
            while(val.count(next))
            {
                length++;
                next++;
            }
            ans=max(ans,length);
        }
        return ans;
    }
};