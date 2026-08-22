class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node)
    {
        vis[node]=true;
        for(int i:adj[node])
        {
            if(!vis[i])
                dfs(adj,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        int n=isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(adj,vis,i);
            }
        }
        return c;
    }
};