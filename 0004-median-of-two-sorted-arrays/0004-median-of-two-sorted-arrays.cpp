class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        if((m+n)%2!=0)
            return nums1[(m+n)/2];
        else
            return (nums1[((m+n)/2)-1]+nums1[(m+n)/2])/2.0;
    }
};