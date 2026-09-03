class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        for(int i:nums)
        {
            int n=i,m=0;
            while(n!=0)
            {
                int r=n%10;
                m=m*10+r;
                n/=10;
            }
            s.insert(m);
        }
        return s.size();
    }
};