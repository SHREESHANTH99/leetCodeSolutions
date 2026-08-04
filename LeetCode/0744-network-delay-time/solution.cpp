class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int nxt=it.first;
                int nxtDist=it.second;
                if(dist[nxt]>dist[node]+nxtDist){
                    dist[nxt]=dist[node]+nxtDist;
                    pq.push({dist[nxt],nxt});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]!=1e9){
                ans=max(ans,dist[i]);
            }else{
                return -1;
            }
        }
        return ans;
    }
};
