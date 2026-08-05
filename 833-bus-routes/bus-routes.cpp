class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int,vector<int>> stopToRoutes;
        for(int i=0;i<routes.size();i++){
            for(int stop:routes[i]){
                stopToRoutes[stop].push_back(i);
            }
        }
        vector<int> visited(routes.size(),0);
        queue<int> q;
        q.push(source);
        int buses=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                if(node==target) return buses;
                for(int nd:stopToRoutes[node]){
                    if(visited[nd]) continue;
                    visited[nd]=1;
                    for(int nextStop:routes[nd]){
                        q.push(nextStop);
                    }
                }

            }
            buses++;
        }
        return -1;
    }
};