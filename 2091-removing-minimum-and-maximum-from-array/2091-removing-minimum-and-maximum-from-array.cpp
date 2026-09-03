class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return n;
        int min_idx=min_element(nums.begin(),nums.end())-nums.begin();
        int max_idx=max_element(nums.begin(),nums.end())-nums.begin();
        int c1=max(min_idx,max_idx)+1;
        int c2=n-min(min_idx,max_idx);
        int c3=min(min_idx,max_idx)+1+(n-max(min_idx,max_idx));
        int del=min({c1,c2,c3});
        return del;
    }
};