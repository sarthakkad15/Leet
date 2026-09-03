class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int o=-1,e=-1,i=0,n=nums1.size();
        if(n==1)
            return true;
        while(i<n && (o==-1 || e==-1))
        {
            if(e==-1 && nums1[i]%2==0)
                e=nums1[i];
            else if(o==-1 && nums1[i]%2!=0)
                o=nums1[i];
            i++;
        }
        if(o==-1 || e==-1)
            return true;
        if(e<o)
            return false;
        return true;
    }
};