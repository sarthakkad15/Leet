class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty())
            return {};
        vector<int> temp = arr;
        int n=arr.size(),c=1;
        sort(temp.begin(),temp.end());
        map<int,int> m;
        m[temp[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(temp[i]==temp[i-1])
                m[temp[i]]=c;
            else
                m[temp[i]]=++c;
        }
        for(int i=0;i<n;i++)
        {
            temp[i]=m[arr[i]];
        }
        return temp;
    }
};