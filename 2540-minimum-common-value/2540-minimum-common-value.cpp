class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        set<int> inter;
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(inter,inter.begin()));
        if(inter.empty())
            return -1;
        return *inter.begin();
    }
};