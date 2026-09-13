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
            int sz=i.second.size();
            if(sz>=3)
            {
                int gap=i.second[1]-i.second[0];
                bool flag=true;
                for(int j=2;j<sz;j++)
                {
                    if(i.second[j]-i.second[j-1] != gap)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                    c++;
            }
        }
        return c;
    }
};