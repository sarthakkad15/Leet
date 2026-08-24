class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path,int node)
    {
        if(path[node])
            return false;
        if(vis[node])
            return true;
        vis[node]=true;
        path[node]=true;
        for(int i:adj[node])
        {
            if(!dfs(adj,vis,path,i))
                return false;
        }
        path[node]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!dfs(adj,vis,path,i))
                return false;
        }
        return true;
    }
};