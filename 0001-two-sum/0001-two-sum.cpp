class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<pair<int,int>> order(j+1);
        for(int i=0;i<=j;i++)
        {
            order[i].first=nums[i];
            order[i].second=i;
        }
        sort(order.begin(),order.end());
        while(i<=j)
        {
            if(order[i].first+order[j].first<target)
                i++;
            else if(order[i].first+order[j].first>target)
                j--;
            else
                break;
        }
        vector<int> a;
        a.push_back(order[i].second);
        a.push_back(order[j].second);
        return a;
    }
};