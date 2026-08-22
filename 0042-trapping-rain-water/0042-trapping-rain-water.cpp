class Solution {
public:
    vector<int> prefixMax(vector<int>& height, int n)
    {
        vector<int> pref(n);
        pref[0]=height[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=max(pref[i-1],height[i]);
        }
        return pref;
    }
    vector<int> suffixMax(vector<int>& height, int n)
    {
        vector<int> suff(n);
        suff[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=max(suff[i+1],height[i]);
        }
        return suff;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        vector<int> leftMax = prefixMax(height,n);
        vector<int> rightMax = suffixMax(height,n);
        for(int i=0;i<n;i++)
        {
            if(height[i]<leftMax[i] && height[i]<rightMax[i])
                total+=min(leftMax[i],rightMax[i])-height[i];
        }
        return total;
    }
};