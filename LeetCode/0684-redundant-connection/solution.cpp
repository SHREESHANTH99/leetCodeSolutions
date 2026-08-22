class Solution {
public:
    bool dfs(int nde,int trgt,vector<vector<int>> &adj,vector<int> &visited){
        if(nde==trgt){
            return true;
        }
        visited[nde]=1;
        for(int ni:adj[nde]){
            if(!visited[ni]){
                if(dfs(ni,trgt,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        int m=edges[0].size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            vector<int> visited(n+1,0);
            if(dfs(u,v,adj,visited)){
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
