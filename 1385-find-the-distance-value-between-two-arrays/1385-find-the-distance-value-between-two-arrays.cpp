class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int n1=arr1.size(),n2=arr2.size(),c=0;
        for(int i=0;i<n1;i++)
        {
            int start=0,end=n2-1,mid;
            bool valid = true;
            while(start<=end)
            {
                mid=start+(end-start)/2;
                if(abs(arr1[i]-arr2[mid])<=d)
                {
                    valid = false;
                    break;
                }
                if(arr2[mid]<arr1[i])
                    start=mid+1;
                else
                    end=mid-1;
            }
            if(valid)
                c++;
        }
        return c;
    }
};