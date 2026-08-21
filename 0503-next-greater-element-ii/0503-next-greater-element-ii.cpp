class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        stack<int> st;
        int n=nums.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            if(st.empty())
            {
                for(int j=0;j<n;j++)
                {
                    if(nums[j]>nums[i])
                    {
                        mp[nums[i]]=nums[j];
                        break;
                    }
                    mp[nums[i]]=-1;
                }
            }
            else
                mp[nums[i]]=st.top();
            st.push(nums[i]);
            ans.push_back(mp[nums[i]]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};