class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int sz = logs.size();
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++)
        {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        sort(logs.begin(),logs.end(),compare);
        vector<int> ans(q.size());
        vector<int> freq(n+1, 0);
        int left=0,right=0,active=0;
        for(auto i:q)
        {
            while(right<sz && logs[right][1]<=i.first)
            {
                if(freq[logs[right][0]]==0)
                    active++;
                freq[logs[right][0]]++;
                right++;
            }
            while(left<right && logs[left][1]<i.first-x)
            {
                freq[logs[left][0]]--;
                if(freq[logs[left][0]]==0)
                    active--;
                left++;
            }
            ans[i.second]=n-active;
        }
        return ans;
    }
};