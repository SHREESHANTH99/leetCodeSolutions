class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        vector<vector<vector<vector<int>>>> dist(m,vector<vector<vector<int>>>(n,vector<vector<int>>(5,vector<int>(k+1,INT_MAX))));
        using State=tuple<int,int,int,int,int>;
        priority_queue<
            State,
            vector<State>,
            greater<State>>pq;
        dist[0][0][4][0]=grid[0][0];
        pq.push({grid[0][0],0,0,4,0});
        int ans=-1;
        while(!pq.empty()){
            auto [cost,r,c,lastDir,turns]=pq.top();
            pq.pop();
            if(cost>dist[r][c][lastDir][turns]) continue;
            if(r==m-1 && c==n-1){
                ans=cost;
                break;
            }
            for(int d=0;d<4;d++){
                int nr=r+dr[d];
                int nc=c+dc[d];
                if(nr<0 || nc<0 ||nr>=m || nc>=n) continue;
                int newT=turns;
                if(lastDir!=4 && lastDir!=d) newT++;
                if(newT>k) continue;
                int newC=cost+grid[nr][nc];
                if(newC<dist[nr][nc][d][newT]){
                    dist[nr][nc][d][newT]=newC;
                    pq.push({newC,nr,nc,d,newT});
                }
            }
        }
        return ans;
    }
};
