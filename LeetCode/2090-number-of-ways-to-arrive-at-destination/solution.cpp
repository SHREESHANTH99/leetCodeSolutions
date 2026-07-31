class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto &it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        const int mod = 1e9 + 7;
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        vector<long long> dista(n, LLONG_MAX);
        vector<int> ways(n,0);
        dista[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist > dista[node]) continue;

            for(auto &it : adj[node]){

                int adjNode = it.first;
                int edW = it.second;

                if(dist + edW < dista[adjNode]){

                    dista[adjNode] = dist + edW;
                    ways[adjNode] = ways[node];
                    pq.push({dista[adjNode], adjNode});

                }
                else if(dist + edW == dista[adjNode]){

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
