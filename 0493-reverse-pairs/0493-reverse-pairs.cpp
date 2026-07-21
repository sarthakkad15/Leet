class Solution {
public:
    int c=0;
    void merge(vector<int>& nums, int start, int mid, int end)
    {
        int y=mid+1;
        for(int x = start; x <= mid; x++)
        {
            while(y <= end && nums[x] > 2LL * nums[y])
                y++;
            c += (y - (mid + 1));
        }
        int i=start,j=mid+1;
        vector<int> temp;
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i <= mid)
            temp.push_back(nums[i++]);
        while(j <= end)
            temp.push_back(nums[j++]);
        for(int k = start; k <= end; k++)
            nums[k] = temp[k - start];
    }
    void divide(vector<int>& nums, int start, int end)
    {
        if(end<=start)
            return;
        int mid=start+(end-start)/2;
        divide(nums,start,mid);
        divide(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    int reversePairs(vector<int>& nums) {
        divide(nums,0,nums.size()-1);
        return c;
    }
};