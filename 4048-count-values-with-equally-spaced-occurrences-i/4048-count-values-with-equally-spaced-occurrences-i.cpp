class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
        }
        int c=0;
        for(auto i:m)
        {
            if(i.second.size()==3 && (i.second[1]-i.second[0] == i.second[2]-i.second[1]))
                c++;
        }
        return c;
    }
};