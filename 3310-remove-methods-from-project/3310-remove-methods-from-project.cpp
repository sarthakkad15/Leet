class Solution {
public:
    void dfs(int k, vector<vector<int>>& adj, vector<int>& susp)
    {
        susp[k]=1;
        for(auto i : adj[k])
        {
            if(!susp[i])
                dfs(i,adj,susp);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> susp(n,0);
        vector<int> ans;
        for(auto i : invocations)
        {
            adj[i[0]].push_back(i[1]);
        }
        dfs(k,adj,susp);
        for(auto i : invocations)
        {
            if(!susp[i[0]] && susp[i[1]])
            {
                for(int i=0;i<n;i++)
                {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!susp[i])
                ans.push_back(i);
        }
        return ans;
    }
};