class Solution {
public:
vector<pair<int,int>> ans;
bool static cmp(const pair<int,int> p1 ,const pair<int,int> p2)
{
    if(p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

void dijkshtra(int src,int n, int distanceThreshold){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    pq.push({0,src});
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
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i!=src && dist[i]<=distanceThreshold){
            cnt++;
        }
    }
    ans.push_back({cnt,src});
}
    vector<pair<int,int>> adj[105];
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        for(int i=0;i<n;i++){
            dijkshtra(i,n,distanceThreshold);
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans[0].second;
    }
};