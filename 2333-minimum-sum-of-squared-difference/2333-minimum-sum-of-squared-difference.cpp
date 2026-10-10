class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> diff(1e5+1,0);
        int k = (k1+k2);
        for(int i=0;i<n;i++)
        {
            int d=abs(nums1[i]-nums2[i]);
            diff[d]++;
        }
        for(int i=1e5;i>0 && k>0;i--)
        {
            int count = min(k,diff[i]);
            diff[i]-=count;
            diff[i-1]+=count;
            k-=count;
        }
        long long sum=0;
        for(int i=0;i<=1e5;i++)
        {
            sum+=(long long)diff[i]*i*i;
        }
        return sum;
    }
};