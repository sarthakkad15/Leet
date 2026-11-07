class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        int x = 0;
        for(int i : nums)
            x ^= i;
        unsigned int set_bit = (unsigned int)x & -(unsigned int)x;
        int a = 0, b = 0;
        for(int i : nums) 
        {
            if((unsigned int)i & set_bit)
                a ^= i;
            else
                b ^= i;
        }
        return {a,b};
    }
};
